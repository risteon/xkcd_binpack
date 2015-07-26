// this is for emacs file handling -*- mode: c++; indent-tabs-mode: nil -*-

// -- BEGIN LICENSE BLOCK ----------------------------------------------
// -- END LICENSE BLOCK ------------------------------------------------

//----------------------------------------------------------------------
/*!\file
 *
 * \author  Christoph Rist <rist.christoph@gmail.com>
 * \date    2014-12-28
 *
 */
//----------------------------------------------------------------------

#ifndef MESSAGE_EXCEPTION_H
#define MESSAGE_EXCEPTION_H

#include <exception>

namespace xkcd_binpack {

class MessageException : public std::exception
{
public:
  MessageException() = delete;

  MessageException(const std::string &message)
          : std::exception(), m_message(message)
  {

  }

  virtual const char *what() const noexcept override

  final
  {
    return m_message.c_str();
  }

private:
  std::string m_message;
};

} // ns

#endif //MESSAGE_EXCEPTION_H
