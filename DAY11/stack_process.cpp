#include <iostream>
using namespace std;
#include <stack>
#include <string>

class Process {
private:
    int pid;
    string process_name;
    bool running_status;

public:
    Process(int pid, string& process_name, bool running_status) : pid(pid), process_name(process_name), running_status(running_status) {}

    friend ostream& operator<<(ostream& os, const Process& process) {
        os << "PID: " << process.pid
           << ", Process Name: " << process.process_name
           << ", Running Status: " << (process.running_status ? "Running" : "Stopped");
        return os;
    }
};

int main() {
    stack<Process> processStack;

    processStack.push(Process(101, "Chrome", true));
    processStack.push(Process(202, "VSCode", true));
    processStack.push(Process(303, "MusicPlayer", false));

    while (!processStack.empty()) {
        cout << "Popping: " << processStack.top() << endl;
        processStack.pop();
    }

    return 0;
}

