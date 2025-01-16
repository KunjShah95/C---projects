#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <stdexcept>

class HttpRequest
{
public:
    std::string method;
    std::string uri;
    std::string httpVersion;
    std::map<std::string, std::string> headers;
    std::string body;

    // Function to parse a raw HTTP request
    void parse(const std::string &rawRequest)
    {
        std::istringstream stream(rawRequest);
        std::string line;

        // Parse the request line (Method, URI, HTTP version)
        if (std::getline(stream, line))
        {
            parseRequestLine(line);
        }
        else
        {
            throw std::runtime_error("Invalid HTTP request: Missing request line");
        }

        // Parse headers
        while (std::getline(stream, line) && line != "\r")
        {
            if (line.empty() || line == "\r")
                break;
            parseHeader(line);
        }

        // Parse body (if Content-Length is present)
        if (headers.find("Content-Length") != headers.end())
        {
            int contentLength = std::stoi(headers["Content-Length"]);
            body.resize(contentLength);
            stream.read(&body[0], contentLength);
        }
    }

    // Print the parsed request for debugging
    void print() const
    {
        std::cout << "Method: " << method << "\n";
        std::cout << "URI: " << uri << "\n";
        std::cout << "HTTP Version: " << httpVersion << "\n";
        std::cout << "Headers:\n";
        for (const auto &header : headers)
        {
            std::cout << "  " << header.first << ": " << header.second << "\n";
        }
        if (!body.empty())
        {
            std::cout << "Body:\n"
                      << body << "\n";
        }
    }

private:
    // Parse the request line (Method, URI, HTTP version)
    void parseRequestLine(const std::string &line)
    {
        std::istringstream requestLine(line);
        requestLine >> method >> uri >> httpVersion;

        if (method.empty() || uri.empty() || httpVersion.empty())
        {
            throw std::runtime_error("Invalid HTTP request line");
        }

        if (httpVersion != "HTTP/1.1" && httpVersion != "HTTP/1.0")
        {
            throw std::runtime_error("Unsupported HTTP version: " + httpVersion);
        }
    }

    // Parse a header line into key-value pairs
    void parseHeader(const std::string &line)
    {
        size_t delimiter = line.find(": ");
        if (delimiter != std::string::npos)
        {
            std::string key = line.substr(0, delimiter);
            std::string value = line.substr(delimiter + 2);
            headers[key] = value;
        }
        else
        {
            throw std::runtime_error("Malformed header: " + line);
        }
    }
};

int main()
{
    // Example raw HTTP request
    std::string rawRequest =
        "POST /api/resource HTTP/1.1\r\n"
        "Host: example.com\r\n"
        "Content-Type: application/json\r\n"
        "Content-Length: 27\r\n"
        "\r\n"
        "{\"key\":\"value\",\"x\":123}";

    try
    {
        HttpRequest request;
        request.parse(rawRequest);
        request.print();
    }
    catch (const std::exception &ex)
    {
        std::cerr << "Error parsing HTTP request: " << ex.what() << "\n";
    }

    return 0;
}
