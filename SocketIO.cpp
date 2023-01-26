#include <sys/socket.h>
#include <stdexcept>
#include <sstream>
#include "SocketIO.h"

SocketIO::SocketIO(int sock) {
    this->sock = sock;
}

bool isValidInteger(const std::string &str) {
    std::istringstream ss(str);
    int x;
    ss >> x;
    return !ss.fail() && ss.eof();
}

void SocketIO::write(const std::string &y) {
    std::string x = y;
    //ADD ZEROS:
    x += DELIM;
    char buffer[CONST + 1];
    size_t len = x.length();
    int index = 0;
    while (len > CONST) {
        len -= CONST;
        strcpy(buffer, x.substr(index, CONST).c_str());
        index += CONST;
        ssize_t sent_bytes = send(sock, buffer, CONST+1, 0);
        if (sent_bytes < 0) {
            throw std::runtime_error("error sending to socket");
        }
    }
    ssize_t sent_bytes = send(sock, x.substr(index).c_str(), strlen(x.substr(index).c_str()) + 1, 0);
    if (sent_bytes < 0) {
        throw std::runtime_error("error sending to socket");
    }

}

std::string SocketIO::read() {
    std::string ret;
    char buffer[CONST + 1] = {0}; // for the message
    char *found;
    ssize_t read_bytes;
    do {
        read_bytes = recv(sock, buffer, CONST+1, 0);
        found = std::find(std::begin(buffer), std::end(buffer), DELIM);
        if (found == std::end(buffer))
            ret += buffer;
        else{
            buffer[strlen(buffer)-1] = '\0';
            ret += buffer;
        }
        if (read_bytes == 0) {
            throw std::runtime_error("connection closed");
        } else if (read_bytes < 0) {
            throw std::runtime_error("error");
        }
    } while (found == std::end(buffer));
    return ret;
}
