#ifndef MESSAGE_EXCEPTION_H
#define MESSAGE_EXCEPTION_H

#include <exception>

class MessageException : public std::exception
{
public:
  MessageException() = delete;
  MessageException(const std::string& message)
    : std::exception()
    , m_message(message)
  {

  }

  virtual const char* what() const noexcept override final
  {
    return m_message.c_str();
  }

private:
  std::string m_message;
};


#endif //MESSAGE_EXCEPTION_H
