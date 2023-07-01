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
///   Date: 6/21/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_ETHERNET_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_ETHERNET_MAIN_OPT_HPP

#include "xos/app/console/verbose/main.hpp"

#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPT "addesss"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTARG "[{ 0..n | string }]"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTUSE "interface address"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTVAL_S "a::"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTION \
   {XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPT, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPT "number"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTARG "[0..n]"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTUSE "interface number"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTVAL_S "n::"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTION \
   {XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPT, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTVAL_C}, \

#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPT "name"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTARG "[string]"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTUSE "interface name"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTVAL_S "m::"
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTION \
   {XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPT, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTARG_RESULT, \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTVAL_S \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTVAL_S \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTVAL_S \

#define XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTION \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTION \
    XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ARGS 0
#define XOS_APP_CONSOLE_ETHERNET_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace ethernet {

/// class main_optt
template
<class TExtends = xos::app::console::verbose::maint<>,  class TImplements = typename TExtends::implements>

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
    main_optt(): run_(0) {
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

    /// ...output_address_named_run
    virtual int output_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_address_named_run(argc, argv, env))) {
            int err2 = 0;
            err = output_address_named_run(argc, argv, env);
            if ((err2 = after_output_address_named_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_address_named_run;
        return err;
    }
    virtual int output_address_named_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_address_named_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_address_named_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_address_run
    virtual int output_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_address_run(argc, argv, env))) {
            int err2 = 0;
            err = output_address_run(argc, argv, env);
            if ((err2 = after_output_address_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_address_run;
        return err;
    }
    virtual int output_address_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_address_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_address_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_name_run
    virtual int output_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_name_run(argc, argv, env))) {
            int err2 = 0;
            err = output_name_run(argc, argv, env);
            if ((err2 = after_output_name_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_name_run;
        return err;
    }
    virtual int output_name_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_name_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_name_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_number_run
    virtual int output_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        unsigned interface_number = this->interface_number();
        unsigned_to_string s_interface_number(interface_number);
        this->outln(s_interface_number);
        return err;
    }
    virtual int before_output_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_number_run(argc, argv, env))) {
            int err2 = 0;
            err = output_number_run(argc, argv, env);
            if ((err2 = after_output_number_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_number_run;
        return err;
    }
    virtual int output_number_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_output_number_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int output_number_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// ...output_actual_address_text_run
    virtual int output_actual_address_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_actual_address_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_actual_address_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_actual_address_text_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_actual_address_text_run(argc, argv, env))) {
            int err2 = 0;
            err = output_actual_address_text_run(argc, argv, env);
            if ((err2 = after_output_actual_address_text_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }

    /// ...addesss_option...
    virtual int on_get_addesss_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_addesss_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_addesss_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        clear_interface_name();
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            const char_t* chars = 0;
            size_t length = 0;

            if ((chars = arg.has_chars(length))) {
                char_t c = 0;
                do {
                    if (!(('9' >= (c = *(chars++))) && ('0' <= c))) {
                        break;
                    } else {
                    }
                } while (0 < --length);
                if ((0 < length)) {
                    set_interface_name(arg);
                } else {
                    unsigned interface_numbered = arg.to_unsigned();
                    set_interface_number(interface_numbered);
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_addesss_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_addesss_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_addesss_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_addesss_option_set(optarg, optind, argc, argv, env))) {
                    if ((0 < (interface_name().length()))) {
                        if (!(err = set_output_address_named_run(argc, argv, env))) {
                            if (!(err = output_address_named_run_set(argc, argv, env))) {
                            } else {
                            }
                        } else {
                        }
                    } else {
                        if (!(err = set_output_address_run(argc, argv, env))) {
                            if (!(err = output_address_run_set(argc, argv, env))) {
                            } else {
                            }
                        } else {
                        }
                    }
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_addesss_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_addesss_option_get(optarg, optind, argc, argv, env))) {
                    if (!(err = set_output_address_run(argc, argv, env))) {
                        if (!(err = output_address_run_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* addesss_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTUSE;
        optarg = XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTARG;
        return chars;
    }

    /// ...name_option...
    virtual int on_get_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_name_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            set_interface_name(optarg);
        } else {
        }
        return err;
    }
    virtual int on_name_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_name_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_name_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_name_option_set(optarg, optind, argc, argv, env))) {
                    if (!(err = set_output_address_named_run(argc, argv, env))) {
                        if (!(err = output_address_named_run_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_name_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_name_option_get(optarg, optind, argc, argv, env))) {
                    if (!(err = set_output_name_run(argc, argv, env))) {
                        if (!(err = output_name_run_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* name_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTUSE;
        optarg = XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTARG;
        return chars;
    }

    /// ...number_option...
    virtual int on_get_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_number_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_number_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            unsigned interface_number = arg.to_unsigned();
            set_interface_number(interface_number);
        } else {
        }
        return err;
    }
    virtual int on_number_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_number_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_number_option_set(optarg, optind, argc, argv, env))) {
                    if (!(err = set_output_address_run(argc, argv, env))) {
                        if (!(err = output_address_run_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_number_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_number_option_get(optarg, optind, argc, argv, env))) {
                    if (!(err = set_output_number_run(argc, argv, env))) {
                        if (!(err = output_number_run_set(argc, argv, env))) {
                        } else {
                        }
                    } else {
                    }
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* number_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTUSE;
        optarg = XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTVAL_C:
            err = this->on_addesss_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTVAL_C:
            err = this->on_name_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTVAL_C:
            err = this->on_number_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_ETHERNET_MAIN_ADDESSS_OPTVAL_C:
            chars = this->addesss_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ETHERNET_MAIN_NAME_OPTVAL_C:
            chars = this->name_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_ETHERNET_MAIN_NUMBER_OPTVAL_C:
            chars = this->number_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_ETHERNET_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_ETHERNET_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_ETHERNET_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...interface_number
    virtual unsigned& set_interface_number(const unsigned& to) {
        unsigned& interface_number = this->interface_number();
        interface_number = to;
        return interface_number;
    }
    virtual unsigned& interface_number() const {
        return (unsigned&)interface_number_;
    }

    /// ...interface_name
    virtual string_t& set_interface_name(const string_t& to) {
        string_t& interface_name = this->interface_name();
        interface_name.assign(to);
        return interface_name;
    }
    virtual string_t& clear_interface_name() {
        string_t& interface_name = this->interface_name();
        interface_name.clear();
        return interface_name;
    }
    virtual string_t& interface_name() const {
        return (string_t&)interface_name_;
    }

protected:
    unsigned interface_number_;
    string_t interface_name_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace ethernet
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_ETHERNET_MAIN_OPT_HPP
