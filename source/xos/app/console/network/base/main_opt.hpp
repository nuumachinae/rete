//////////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2023 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 9/3/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPT_HPP

#include "xos/app/console/base/main.hpp"

#define XOS_APP_CONSOLE_NETWORK_MESSAGE_SENT_DEFAUTLT \
    "GET /hello HTTP/1.0\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n" \

#define XOS_APP_CONSOLE_NETWORK_MESSAGE_RECEIVED_DEFAUTLT \
    "HTTP/1.0 200 Ok\r\n" \
    "Content-Type:text/plain\r\n" \
    "Content-Length:7\r\n\r\n" \
    "hello\r\n" \
    
//////////////////////////////////////////////////////////////////////////

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPT "send"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTARG "[message]"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTUSE "send message"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_C 's'
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTION \
   {XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPT "receive"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTARG "[message]"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTUSE "receive message"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_S "r::"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_C 'r'
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTION \
   {XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPT "sent"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTARG "[string]"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTUSE "message sent"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_S "S::"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_C 'S'
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTION \
   {XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPT "received"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTARG "[string]"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTUSE "message received"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_S "R::"
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_C 'R'
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTION \
   {XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTARG_RESULT, \
    XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTION \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTION \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTION \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_S \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_S \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTION \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTION \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTION \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_BASE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_ARGS 0
#define XOS_APP_CONSOLE_NETWORK_BASE_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace network {
namespace base {

/// class main_optt
template 
<class TExtends = xos::app::console::base::maint<>,  class TImplements = typename TExtends::implements>

class main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt()
    : run_(0), 
      message_sent_(XOS_APP_CONSOLE_NETWORK_MESSAGE_SENT_DEFAUTLT),
      message_received_(XOS_APP_CONSOLE_NETWORK_MESSAGE_RECEIVED_DEFAUTLT) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...send_message_run
    int (derives::*send_message_run_)(int argc, char_t** argv, char_t** env);
    virtual int send_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (send_message_run_) {
            if (!(err = (this->*send_message_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_send_message_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_send_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = output_message_sent_run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_send_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_send_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_send_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_send_message_run(argc, argv, env))) {
            int err2 = 0;
            err = send_message_run(argc, argv, env);
            if ((err2 = after_send_message_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_send_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_send_message_run;
        return err;
    }
    virtual int send_message_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_send_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int send_message_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...receive_message_run
    int (derives::*receive_message_run_)(int argc, char_t** argv, char_t** env);
    virtual int receive_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (receive_message_run_) {
            if (!(err = (this->*receive_message_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_receive_message_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_receive_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& message = this->message_received();
        if (!(err = this->input_string_message(message, argc, argv, env))) {
            if (!(err = message_received_run(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_receive_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_receive_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_receive_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_receive_message_run(argc, argv, env))) {
            int err2 = 0;
            err = receive_message_run(argc, argv, env);
            if ((err2 = after_receive_message_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_receive_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_receive_message_run;
        return err;
    }
    virtual int receive_message_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_receive_message_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int receive_message_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...message_received_run
    int (derives::*message_received_run_)(int argc, char_t** argv, char_t** env);
    virtual int message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (message_received_run_) {
            if (!(err = (this->*message_received_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_message_received_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& message = this->message_received();
        if (!(err = all_prepare_message_received(message, argc, argv, env))) {
            if (!(err = all_process_message_received(message, argc, argv, env))) {
                if (!(err = all_output_message_received(message, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int before_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_message_received_run(argc, argv, env))) {
            int err2 = 0;
            err = message_received_run(argc, argv, env);
            if ((err2 = after_message_received_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_message_received_run;
        return err;
    }
    virtual int message_received_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int message_received_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////

    /// ...output_message_sent_run
    int (derives::*output_message_sent_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_message_sent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_message_sent_run_) {
            if (!(err = (this->*output_message_sent_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_message_sent_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_message_sent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& message = this->message_sent();
        const char_t* chars = 0;
        size_t length = 0;
        if ((chars = message.chars(length))) {
            this->outln(chars, length);
        } else {
        }
        return err;
    }
    virtual int before_output_message_sent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_message_sent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_message_sent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_message_sent_run(argc, argv, env))) {
            int err2 = 0;
            err = output_message_sent_run(argc, argv, env);
            if ((err2 = after_output_message_sent_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_message_sent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_message_sent_run;
        return err;
    }
    virtual int output_message_sent_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_message_sent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_message_sent_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_message_received_run
    int (derives::*output_message_received_run_)(int argc, char_t** argv, char_t** env);
    virtual int output_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_message_received_run_) {
            if (!(err = (this->*output_message_received_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_message_received_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        string_t& message = this->message_received();
        const char_t* chars = 0;
        size_t length = 0;
        if ((chars = message.chars(length))) {
            this->outln(chars, length);
        } else {
        }
        return err;
    }
    virtual int before_output_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_message_received_run(argc, argv, env))) {
            int err2 = 0;
            err = output_message_received_run(argc, argv, env);
            if ((err2 = after_output_message_received_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_message_received_run;
        return err;
    }
    virtual int output_message_received_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_message_received_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_message_received_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////

    /// ...prepare_message_to_send
    int (derives::*prepare_message_to_send_)(string_t& message, int argc, char_t** argv, char_t** env);
    virtual int prepare_message_to_send(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_message_to_send_) {
            if (!(err = (this->*prepare_message_to_send_)(message, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_prepare_message_to_send(message, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_prepare_message_to_send(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_message_to_send(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_to_send(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_to_send(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_to_send(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_to_send(message, argc, argv, env);
            if ((err2 = after_prepare_message_to_send(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_prepare_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_to_send_ = &derives::all_prepare_message_to_send;
        return err;
    }
    virtual int prepare_message_to_send_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_message_to_send(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_to_send_ = 0;
        return err;
    }
    virtual int prepare_message_to_send_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...prepare_message_received
    int (derives::*prepare_message_received_)(string_t& message, int argc, char_t** argv, char_t** env);
    virtual int prepare_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (prepare_message_received_) {
            if (!(err = (this->*prepare_message_received_)(message, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_prepare_message_received(message, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_prepare_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_prepare_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_prepare_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_prepare_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_prepare_message_received(message, argc, argv, env))) {
            int err2 = 0;
            err = prepare_message_received(message, argc, argv, env);
            if ((err2 = after_prepare_message_received(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = &derives::all_prepare_message_received;
        return err;
    }
    virtual int prepare_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_prepare_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        prepare_message_received_ = 0;
        return err;
    }
    virtual int prepare_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...process_message_received
    int (derives::*process_message_received_)(string_t& message, int argc, char_t** argv, char_t** env);
    virtual int process_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (process_message_received_) {
            if (!(err = (this->*process_message_received_)(message, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_process_message_received(message, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_process_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_process_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_process_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_process_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_process_message_received(message, argc, argv, env))) {
            int err2 = 0;
            err = process_message_received(message, argc, argv, env);
            if ((err2 = after_process_message_received(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_process_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        process_message_received_ = &derives::all_process_message_received;
        return err;
    }
    virtual int process_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_process_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        process_message_received_ = 0;
        return err;
    }
    virtual int process_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_message_received
    int (derives::*output_message_received_)(string_t& message, int argc, char_t** argv, char_t** env);
    virtual int output_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (output_message_received_) {
            if (!(err = (this->*output_message_received_)(message, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_output_message_received(message, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_output_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->outln(message);
        return err;
    }
    virtual int before_output_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_message_received(message, argc, argv, env))) {
            int err2 = 0;
            err = output_message_received(message, argc, argv, env);
            if ((err2 = after_output_message_received(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_message_received_ = &derives::all_output_message_received;
        return err;
    }
    virtual int output_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        output_message_received_ = 0;
        return err;
    }
    virtual int output_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...input_message_received
    int (derives::*input_message_received_)(string_t& message, int argc, char_t** argv, char_t** env);
    virtual int input_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (input_message_received_) {
            if (!(err = (this->*input_message_received_)(message, argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_input_message_received(message, argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_input_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_input_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_input_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_input_message_received(string_t& message, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_input_message_received(message, argc, argv, env))) {
            int err2 = 0;
            err = input_message_received(message, argc, argv, env);
            if ((err2 = after_input_message_received(message, argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_input_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_received_ = &derives::all_input_message_received;
        return err;
    }
    virtual int input_message_received_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_input_message_received(int argc, char_t** argv, char_t** env) {
        int err = 0;
        input_message_received_ = 0;
        return err;
    }
    virtual int input_message_received_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    ///////////////////////////////////////////////////////////////////////

    /// on...send_option...
    virtual int on_get_send_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_send_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_send_message_run(argc, argv, env))) {
            if (!(err = send_message_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_send_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& message = this->message_sent();
            if (!(err = this->on_set_string_message_option(message, optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_send_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_send_message_run(argc, argv, env))) {
            if (!(err = send_message_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_send_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_send_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_send_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_send_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_send_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* send_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTARG;
        return chars;
    }

    /// on...receive_option...
    virtual int on_get_receive_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_receive_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_receive_message_run(argc, argv, env))) {
            if (!(err = receive_message_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_receive_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& message = this->message_received();
            if (!(err = this->on_set_string_message_option(message, optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_receive_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_message_received_run(argc, argv, env))) {
            if (!(err = message_received_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_receive_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_receive_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_receive_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_receive_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_receive_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* receive_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTARG;
        return chars;
    }

    /// on...message_sent_option...
    virtual int on_get_message_sent_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_message_sent_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_message_sent_run(argc, argv, env))) {
            if (!(err = output_message_sent_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_message_sent_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& message = this->message_sent();
            if (!(err = this->on_set_string_message_option(message, optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_message_sent_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_message_sent_run(argc, argv, env))) {
            if (!(err = output_message_sent_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_message_sent_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_message_sent_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_message_sent_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_message_sent_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_message_sent_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* message_sent_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTARG;
        return chars;
    }

    /// on...message_received_option...
    virtual int on_get_message_received_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_message_received_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_message_received_run(argc, argv, env))) {
            if (!(err = output_message_received_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_message_received_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t& message = this->message_received();
            if (!(err = this->on_set_string_message_option(message, optarg, optind, argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_message_received_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_output_message_received_run(argc, argv, env))) {
            if (!(err = output_message_received_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_message_received_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_message_received_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_message_received_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_message_received_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_message_received_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* message_received_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTUSE;
        optarg = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_C:
            err = this->on_send_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_C:
            err = this->on_receive_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_C:
            err = this->on_message_sent_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_C:
            err = this->on_message_received_option(optval, optarg, optname, optind, argc, argv, env);
            break;

        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    
    /// option_usage
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {

        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_SEND_OPTVAL_C:
            chars = this->send_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_RECEIVE_OPTVAL_C:
            chars = this->receive_option_usage(optarg, longopt);
            break;

        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_SENT_OPTVAL_C:
            chars = this->message_sent_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_NETWORK_BASE_MAIN_MESSAGE_RECEIVED_OPTVAL_C:
            chars = this->message_received_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_NETWORK_BASE_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_NETWORK_BASE_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    ///////////////////////////////////////////////////////////////////////

    /// ...message_sent
    virtual string_t& set_message_sent(const string_t& to) {
        string_t& message_sent = this->message_sent();
        message_sent.assign(to);
        return message_sent;
    }
    virtual string_t& set_message_sent(const char_t* to) {
        string_t& message_sent = this->message_sent();
        message_sent.assign(to);
        return message_sent;
    }
    virtual string_t& set_message_sent(const char_t* to, size_t length) {
        string_t& message_sent = this->message_sent();
        message_sent.assign(to, length);
        return message_sent;
    }
    virtual string_t& message_sent() const {
        return (string_t&)message_sent_;
    }

    /// ...message_received
    virtual string_t& set_message_received(const string_t& to) {
        string_t& message_received = this->message_received();
        message_received.assign(to);
        return message_received;
    }
    virtual string_t& set_message_received(const char_t* to) {
        string_t& message_received = this->message_received();
        message_received.assign(to);
        return message_received;
    }
    virtual string_t& set_message_received(const char_t* to, size_t length) {
        string_t& message_received = this->message_received();
        message_received.assign(to, length);
        return message_received;
    }
    virtual string_t& message_received() const {
        return (string_t&)message_received_;
    }

    /// ...message
    virtual string_t& set_message(const string_t& to) {
        string_t& message = this->message();
        message.assign(to);
        return message;
    }
    virtual string_t& set_message(const char_t* to) {
        string_t& message = this->message();
        message.assign(to);
        return message;
    }
    virtual string_t& set_message(const char_t* to, size_t length) {
        string_t& message = this->message();
        message.assign(to, length);
        return message;
    }
    virtual string_t& message() const {
        return (string_t&)message_;
    }

    /// ...accept...
    virtual bool& set_accept_many(bool to = false) {
        bool& is_true = this->accept_one();
        is_true = to;
        return is_true;
    }
    virtual bool& set_accept_one(bool to = true) {
        bool& is_true = this->accept_one();
        is_true = to;
        return is_true;
    }
    virtual bool& accept_one() const {
        return (bool&)accept_one_;
    }
    
    /// ...accept...
    virtual bool& set_accept_continue(bool to = true) {
        accept_done_ = !to;
        return (bool&)accept_done_;
    }
    virtual bool& set_accept_done(bool to = true) {
        accept_done_ = to;
        return (bool&)accept_done_;
    }
    virtual bool& accept_done() const {
        return (bool&)accept_done_;
    }

    /// ...accept...
    virtual bool& set_accept_stop(bool to = true) {
        accept_restart_ = !to;
        return (bool&)accept_restart_;
    }
    virtual bool& set_accept_restart(bool to = true) {
        accept_restart_ = to;
        return (bool&)accept_restart_;
    }
    virtual bool& accept_restart() const {
        return (bool&)accept_restart_;
    }

    /// ...request / ...response
    virtual string_t& request() const {
        string_t& message = this->message_sent();
        return message;
    }
    virtual string_t& response() const {
        string_t& message = this->message_received();
        return message;
    }

protected:
    string_t message_sent_, message_received_, message_;
    bool accept_one_, accept_done_, accept_restart_;
}; /// class main_optt 
typedef main_optt<> main_opt;

} /// namespace base 
} /// namespace network 
} /// namespace console 
} /// namespace app 
} /// namespace xos 

#endif /// ndef XOS_APP_CONSOLE_NETWORK_BASE_MAIN_OPT_HPP
