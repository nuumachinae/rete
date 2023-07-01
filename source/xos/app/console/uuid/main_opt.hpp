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
///   Date: 6/22/2023
//////////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_UUID_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_UUID_MAIN_OPT_HPP

#include "xos/app/console/verbose/main.hpp"

#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPT "ethernet"
#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTARG "[{ 0..n | xx:xx:xx:xx:xx:xx | string }]"
#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTUSE "ethernet [index] / address / name"
#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTION \
   {XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPT, \
    XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTARG_RESULT, \
    XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTVAL_S \

#define XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTION \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_CHARS \

#define XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_VERBOSE_MAIN_OPTIONS_OPTIONS \

///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_UUID_MAIN_ARGS 0
#define XOS_APP_CONSOLE_UUID_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace uuid {

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
    main_optt()
    : run_(0), ethernet_index_(0) {
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

    /// ...default_run
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = all_generate_uuid_run(argc, argv, env))) {
        } else {
        }
        return err;
    }

    /// ...generate_uuid_run
    int (derives::*generate_uuid_run_)(int argc, char_t** argv, char_t** env);
    virtual int generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (generate_uuid_run_) {
            if (!(err = (this->*generate_uuid_run_)(argc, argv, env))) {
            } else {
            }
        } else {
            if (!(err = default_generate_uuid_run(argc, argv, env))) {
            } else {
            }
        }
        return err;
    }
    virtual int default_generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = extends::run(argc, argv, env))) {
        } else {
        }
        return err;
    }
    virtual int before_generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_generate_uuid_run(argc, argv, env))) {
            int err2 = 0;
            err = generate_uuid_run(argc, argv, env);
            if ((err2 = after_generate_uuid_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_generate_uuid_run;
        return err;
    }
    virtual int generate_uuid_run_set(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int unset_generate_uuid_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = 0;
        return err;
    }
    virtual int generate_uuid_run_unset(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }

    /// on...ethernet_index_option...
    virtual int on_get_ethernet_index_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_ethernet_index_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_ethernet_index_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            string_t arg(optarg);
            int ethernet_index = 0;
            if (0 <= (ethernet_index = arg.to_signed())) {
                this->set_ethernet_index(ethernet_index);
            }
        } else {
        }
        return err;
    }
    virtual int on_ethernet_index_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }

    /// on...ethernet_address_option...
    virtual int on_get_ethernet_address_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_ethernet_address_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_ethernet_address_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_ethernet_address_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }

    /// on...ethernet_name_option...
    virtual int on_get_ethernet_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_ethernet_name_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_set_ethernet_name_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual int on_ethernet_name_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }

    /// on...ethernet_option...
    virtual int on_get_ethernet_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        return err;
    }
    virtual int on_ethernet_option_get
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if (!(err = set_generate_uuid_run(argc, argv, env))) {
            if (!(err = generate_uuid_run_set(argc, argv, env))) {
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_set_ethernet_option
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_ethernet_index_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_ethernet_index_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_ethernet_option_set
    (const char_t* optarg, int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = set_generate_uuid_run(argc, argv, env))) {
                if (!(err = generate_uuid_run_set(argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
        }
        return err;
    }
    virtual int on_ethernet_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_ethernet_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_ethernet_option_set(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        } else {
            if (!(err = on_get_ethernet_option(optarg, optind, argc, argv, env))) {
                if (!(err = on_ethernet_option_get(optarg, optind, argc, argv, env))) {
                } else {
                }
            } else {
            }
        }
        return err;
    }
    virtual const char_t* ethernet_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTUSE;
        optarg = XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTARG;
        return chars;
    }

    /// on_option
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {

        case XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTVAL_C:
            err = this->on_ethernet_option(optval, optarg, optname, optind, argc, argv, env);
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

        case XOS_APP_CONSOLE_UUID_MAIN_ETHERNET_OPTVAL_C:
            chars = this->ethernet_option_usage(optarg, longopt);
            break;

        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }

    /// options
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_UUID_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// arguments
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_UUID_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_UUID_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

    /// ...ethernet_index
    virtual int& set_ethernet_index(const int& to) {
        int& ethernet_index = this->ethernet_index();
        ethernet_index = to;
        return ethernet_index;
    }
    virtual int& ethernet_index() const {
        return (int&)ethernet_index_;
    }

protected:
    int ethernet_index_;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace uuid
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_UUID_MAIN_OPT_HPP
