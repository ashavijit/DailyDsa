#include <iostream>
#include <map>
#include <vector>
#include <string>

class IPrinter
{
public:
    virtual ~IPrinter() = default;
    virtual void OnMessageComplete(const std::string &message) const = 0;
};

class Printer : public IPrinter
{
public:
    void OnMessageComplete(const std::string &message) const override
    {
        std::cout << message << std::endl;
    }
};

class Decoder
{
public:
    Decoder(const IPrinter &printer)
        : mPrinter(printer)
    {
    }

    void ProcessSample(uint64_t sequence, char character)
    {
        // If the character is '-', it marks the end of a message
        if (character == '-')
        {
            // Check if the message is complete
            if (!currentMessage.empty())
            {
                // Store the message with its sequence number
                messages[sequence] = currentMessage;
                currentMessage.clear();
            }
        }
        else
        {
            // Add the character to the current message
            currentMessage += character;
        }

        // Check if a new message with a higher sequence number has arrived
        auto it = messages.lower_bound(sequence);
        if (it != messages.end())
        {
            // Output the latest message
            mPrinter.OnMessageComplete(it->second);
            // Remove older messages
            messages.erase(messages.begin(), it);
        }
    }

private:
    const IPrinter &mPrinter;
    std::string currentMessage;
    std::map<uint64_t, std::string> messages;
};

int main()
{
    Printer printer;
    Decoder decoder(printer);

    uint64_t seqNum;
    char message;

    while (std::cin >> seqNum >> message)
    {
        decoder.ProcessSample(seqNum, message);
    }

    return 0;
}
