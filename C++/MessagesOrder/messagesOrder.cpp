//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Message {
public:
  Message( int num, std::string text ) : c_messageNum( num ), c_text( text )  { }

  const string &get_text() {
      return( c_text );
  }

  friend bool operator<(const Message& l, const Message& r) {
      return( l.c_messageNum < r.c_messageNum );
  }

  friend bool operator>(const Message& l, const Message& r) {
      return( l.c_messageNum > r.c_messageNum );
  }

private:
  int c_messageNum;

  std::string c_text;
};

class MessageFactory {
public:
  MessageFactory() {
      messageNum = 0;
  }

  Message create_message(const string &text) {
      return( Message( ++messageNum, text ) );
  }

private:
  int messageNum;
};

class Recipient {
public:
  Recipient() {}
  void receive(const Message &msg) { messages_.push_back(msg); }
  void print_messages() {
    fix_order();
    for (auto &msg : messages_) {
      cout << msg.get_text() << endl;
    }
    messages_.clear();
  }

private:
  void fix_order() { sort(messages_.begin(), messages_.end()); }
  vector<Message> messages_;
};

class Network {
public:
  static void send_messages(vector<Message> messages, Recipient &recipient) {
    // simulates the unpredictable network, where sent messages might arrive in
    // unspecified order
    random_shuffle(messages.begin(), messages.end());
    for (auto msg : messages) {
      recipient.receive(msg);
    }
  }
};

int main() {
  MessageFactory message_factory;
  Recipient recipient;
  vector<Message> messages;
  string text;
  while (getline(cin, text)) {
    messages.push_back(message_factory.create_message(text));
  }
  Network::send_messages(messages, recipient);
  recipient.print_messages();
}