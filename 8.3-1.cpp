// 8.3-1.cpp : 



#include <iostream>
#include <fstream>

class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class printToFile : public LogCommand {
public:
    printToFile() {};
    void print(const std::string& message) override {
        std::ofstream file("text.txt");
        file << message << std::endl;
        file.close();
    }
};

class printToConsole : public LogCommand {
public:
    printToConsole() {};
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

void print(LogCommand& com, const std::string& message) {
    com.print(message);
}



int main() {
    printToFile f();
    printToConsole c();

    print(f, "hello");
    print(c, "hello");
}