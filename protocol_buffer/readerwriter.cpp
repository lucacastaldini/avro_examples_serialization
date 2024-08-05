#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <string>
#include <google/protobuf/message.h>
#include "HK.pb.h"  // Include your generated header file for protobuf messages

// Thread-safe queue implementation
template <typename T>
class ThreadSafeQueue {
public:
    void push(const T& item) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(item);
        cond_var_.notify_one();  // Notify any waiting threads
    }

    bool pop(T& item) {
        std::unique_lock<std::mutex> lock(mutex_);
        cond_var_.wait(lock, [this]() { return !queue_.empty(); });
        item = queue_.front();
        queue_.pop();
        return true;
    }

private:
    std::queue<T> queue_;
    std::mutex mutex_;
    std::condition_variable cond_var_;
};

// Function to generate a HeaderHK message
Header generateMessage() {
    Header message;
    message.set_apid(1);
    message.set_counter(123);
    message.set_type(456);
    message.set_abstime(789);
    message.set_runid(101112);
    message.set_configid(131415);
    message.set_wformcount(161718);
    message.set_flags(192021);
    message.set_crc(222324);

    return message;
}

// Writer class
class MessageWriter {
public:
    MessageWriter(ThreadSafeQueue<std::string>& queue) : queue_(queue) {}

    void writeMessage(const Header& message) {
        // Serialize the message to a string
        std::string serialized_message;
        if (!message.SerializeToString(&serialized_message)) {
            std::cerr << "Failed to serialize the message." << std::endl;
            return;
        }

        // Push the serialized message into the shared queue
        queue_.push(serialized_message);
    }

private:
    ThreadSafeQueue<std::string>& queue_;
};

// Reader class
class MessageReader {
public:
    MessageReader(ThreadSafeQueue<std::string>& queue) : queue_(queue) {}

    bool readMessage(Header& message) {
        std::string serialized_message;
        if (!queue_.pop(serialized_message)) {
            std::cerr << "Failed to pop message from queue." << std::endl;
            return false;
        }

        // Deserialize the message from the string
        if (!message.ParseFromString(serialized_message)) {
            std::cerr << "Failed to deserialize the message." << std::endl;
            return false;
        }

        return true;
    }

private:
    ThreadSafeQueue<std::string>& queue_;
};

// Main function demonstrating usage
int main() {
    ThreadSafeQueue<std::string> sharedQueue;
    MessageWriter writer(sharedQueue);
    MessageReader reader(sharedQueue);

    // Generate a message and write it to the queue
    Header message = generateMessage();
    writer.writeMessage(message);

    // Read the message from the queue
    Header received_message;
    if (reader.readMessage(received_message)) {
        std::cout << "Received HeaderHK message:" << std::endl;
        std::cout << "APID: " << received_message.apid() << std::endl;
        std::cout << "Counter: " << received_message.counter() << std::endl;
        // Output other fields as needed
    } else {
        std::cerr << "Failed to read the message." << std::endl;
    }

    return 0;
}
