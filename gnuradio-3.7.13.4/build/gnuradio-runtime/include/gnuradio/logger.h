/* -*- c++ -*- */
/*
 * Copyright 2012-2013 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

/*******************************************************************************
* Author: Mark Plett
* Description:
*   The gr::logger module wraps the log4cpp library for logging in gnuradio
*******************************************************************************/

#ifndef INCLUDED_GR_LOGGER_H
#define INCLUDED_GR_LOGGER_H

/*!
* \ingroup logging
* \brief GNU Radio logging wrapper for log4cpp library (C++ port of log4j)
*
*/

// handle current status of GR_LOG
#ifdef EXT_ENABLE_GR_LOG
#undef EXT_ENABLE_GR_LOG
#endif
#ifdef ENABLE_GR_LOG
#define EXT_ENABLE_GR_LOG
#undef ENABLE_GR_LOG
#endif

// did GR enable LOG?
#define ENABLE_GR_LOG

// if GR does not provide logging and the current module is requesting
// it, disable it.
#if defined(EXT_ENABLE_GR_LOG) && !defined(ENABLE_GR_LOG)
#warning "Logging was requested but is not enabled in GNU Radio, so disabling."
#undef EXT_ENABLE_GR_LOG
#endif

// if GR provides logging but the current module is not requesting it,
// disable it.
#if !defined(EXT_ENABLE_GR_LOG) && defined(ENABLE_GR_LOG)
#undef ENABLE_GR_LOG
#endif

// the other 2 cases work; no need to check them!

// handle current status of LOG4CPP
#ifdef EXT_HAVE_LOG4CPP
#undef EXT_HAVE_LOG4CPP
#endif
#ifdef HAVE_LOG4CPP
#define EXT_HAVE_LOG4CPP
#undef HAVE_LOG4CPP
#endif

// did GR use log4cpp?
/* #undef HAVE_LOG4CPP */

// if GR does not use log4cpp and the current module is requesting it,
// disable it & print a warning.
#if defined(EXT_HAVE_LOG4CPP) && !defined(HAVE_LOG4CPP)
#warning "Log4Cpp use was requested but was not in GNU Radio, so disabling."
#undef EXT_HAVE_LOG4CPP
#endif

// if GR provides for using log4cpp but the current module is not
// requesting it, disable it quietly.
#if !defined(EXT_HAVE_LOG4CPP) && defined(HAVE_LOG4CPP)
#undef HAVE_LOG4CPP
#endif

// the other 2 cases work; no need to check them!

#ifdef _MSC_VER
typedef unsigned short mode_t;
#else
#include <sys/types.h>
#endif

#include <gnuradio/api.h>
#include <assert.h>
#include <iostream>
#include <time.h>
#include <boost/filesystem.hpp>
#include <boost/thread.hpp>
#include <boost/format.hpp>
#include <pmt/pmt.h>

#ifdef ENABLE_GR_LOG

// We have three configurations... first logging to stdout/stderr
#ifndef HAVE_LOG4CPP

namespace gr {
  //#warning GR logging Enabled and using std::cout
  typedef void* logger_ptr;
} /* namespace gr */

#define GR_LOG_DECLARE_LOGPTR(logger)
#define GR_LOG_ASSIGN_LOGPTR(logger,name)
#define GR_CONFIG_LOGGER(config)
#define GR_CONFIG_AND_WATCH_LOGGER(config,period)
#define GR_LOG_GETLOGGER(logger, name)
#define GR_SET_LEVEL(name, level)
#define GR_LOG_SET_LEVEL(logger, level)
#define GR_GET_LEVEL(name, level)
#define GR_LOG_GET_LEVEL(logger, level)
#define GR_ADD_APPENDER(name,appender)
#define GR_LOG_ADD_APPENDER(logger,appender)
#define GR_SET_APPENDER(name,appender)
#define GR_LOG_SET_APPENDER(logger,appender)
#define GR_ADD_CONSOLE_APPENDER(logger,target,pattern)
#define GR_LOG_ADD_CONSOLE_APPENDER(logger,target,pattern)
#define GR_SET_CONSOLE_APPENDER(logger,target,pattern)
#define GR_LOG_SET_CONSOLE_APPENDER(logger,target,pattern)
#define GR_ADD_FILE_APPENDER(name,filename,append,pattern)
#define GR_LOG_ADD_FILE_APPENDER(logger,filename,append,pattern)
#define GR_SET_FILE_APPENDER(name,filename,append,pattern)
#define GR_LOG_SET_FILE_APPENDER(logger,filename,append,pattern)
#define GR_ADD_ROLLINGFILE_APPENDER(name,filename,filesize,bkup_index,append,mode,pattern)
#define GR_LOG_ADD_ROLLINGFILE_APPENDER(logger,filename,filesize,bkup_index,append,mode,pattern)
#define GR_GET_LOGGER_NAMES(names)
#define GR_RESET_CONFIGURATION()
#define GR_DEBUG(name, msg) std::cout<<"DEBUG: "<<msg<<std::endl
#define GR_INFO(name, msg) std::cout<<"INFO: "<<msg<<std::endl
#define GR_NOTICE(name, msg) std::cout<<"NOTICE: "<<msg<<std::endl
#define GR_WARN(name, msg) std::cerr<<"WARN: "<<msg<<std::endl
#define GR_ERROR(name, msg) std::cerr<<"ERROR: "<<msg<<std::endl
#define GR_ALERT(name, msg) std::cerr<<"ERROR: "<<msg<<std::endl
#define GR_CRIT(name, msg) std::cerr<<"ERROR: "<<msg<<std::endl
#define GR_FATAL(name, msg) std::cerr<<"FATAL: "<<msg<<std::endl
#define GR_EMERG(name, msg) std::cerr<<"EMERG: "<<msg<<std::endl
#define GR_ERRORIF(name, cond, msg) {if((cond)) std::cerr<<"ERROR: "<<msg<<std::endl;}
#define GR_ASSERT(name, cond, msg) {if(!(cond)) std::cerr<<"FATAL: "<<msg<<std::endl; assert(cond);}
#define GR_LOG_DEBUG(logger, msg) std::cout<<"DEBUG: "<<msg<<std::endl
#define GR_LOG_INFO(logger, msg) std::cout<<"INFO: "<<msg<<std::endl
#define GR_LOG_NOTICE(logger, msg) std::cout<<"NOTICE: "<<msg<<std::endl
#define GR_LOG_WARN(logger, msg) std::cerr<<"WARN: "<<msg<<std::endl
#define GR_LOG_ERROR(logger, msg) std::cerr<<"ERROR: "<<msg<<std::endl
#define GR_LOG_ALERT(logger, msg) std::cerr<<"ALERT: "<<msg<<std::endl
#define GR_LOG_CRIT(logger, msg) std::cerr<<"CRIT: "<<msg<<std::endl
#define GR_LOG_FATAL(logger, msg) std::cerr<<"FATAL: "<<msg<<std::endl
#define GR_LOG_EMERG(logger, msg) std::cerr<<"EMERG: "<<msg<<std::endl
#define GR_LOG_ERRORIF(logger, cond, msg) {             \
    if((cond)) std::cerr<<"ERROR: "<<msg<<std::endl;}
#define GR_LOG_ASSERT(logger, cond, msg) {                              \
    if(!(cond)) {std::cerr<<"FATAL: "<<msg<<std::endl; assert(cond);};}


#else /* HAVE_LOG4CPP */

// Second configuration...logging to log4cpp
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>

namespace gr {

  /*!
   * \brief GR_LOG macros
   * \ingroup logging
   *
   * These macros wrap the standard LOG4CPP_LEVEL macros.  The availablie macros
   * are:
   *  LOG_DEBUG
   *  LOG_INFO
   *  LOG_WARN
   *  LOG_TRACE
   *  LOG_ERROR
   *  LOG_ALERT
   *  LOG_CRIT
   *  LOG_FATAL
   *  LOG_EMERG
   */
  typedef log4cpp::Category* logger_ptr;

} /* namespace gr */


  /* Macros for Programmatic Configuration */
#define GR_LOG_DECLARE_LOGPTR(logger)           \
  gr::logger_ptr logger;

#define GR_LOG_ASSIGN_LOGPTR(logger,name)       \
  logger = gr::logger_get_logger(name);

#define GR_CONFIG_LOGGER(config)                \
  gr::logger_config::load_config(config)

#define GR_CONFIG_AND_WATCH_LOGGER(config,period)	\
  gr::logger_config::load_config(config,period)

#define GR_LOG_GETLOGGER(logger, name)                  \
  gr::logger_ptr logger = gr::logger_get_logger(name);

#define GR_SET_LEVEL(name, level) {                             \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    gr::logger_set_level(logger,level);}

#define GR_LOG_SET_LEVEL(logger, level)         \
  gr::logger_set_level(logger, level);

#define GR_GET_LEVEL(name, level) {                             \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    gr::logger_get_level(logger,level);}

#define GR_LOG_GET_LEVEL(logger, level)         \
  gr::logger_get_level(logger,level);

#define GR_ADD_APPENDER(name, appender) {                       \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    gr::logger_add_appender(logger,appender);}

#define GR_LOG_ADD_APPENDER(logger, appender) { \
    gr::logger_add_appender(logger, appender);}

#define GR_SET_APPENDER(name, appender) {                       \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    gr::logger_set_appender(logger,appender);}

#define GR_LOG_SET_APPENDER(logger, appender) { \
    gr::logger_set_appender(logger, appender);}

#define GR_ADD_CONSOLE_APPENDER(name, target, pattern) {        \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    gr::logger_add_console_appender(logger,target,pattern);}

#define GR_LOG_ADD_CONSOLE_APPENDER(logger, target, pattern) {  \
    gr::logger_add_console_appender(logger,target,pattern);}

#define GR_SET_CONSOLE_APPENDER(name, target, pattern) {        \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    gr::logger_set_console_appender(logger,target,pattern);}

#define GR_LOG_SET_CONSOLE_APPENDER(logger, target, pattern) {  \
    gr::logger_set_console_appender(logger,target,pattern);}

#define GR_ADD_FILE_APPENDER(name, filename, append, pattern) {         \
    gr::logger_ptr logger = gr::logger_get_logger(name);                \
    gr::logger_add_file_appender(logger,filename,append,pattern);}

#define GR_LOG_ADD_FILE_APPENDER(logger, filename, append, pattern) {   \
    gr::logger_add_file_appender(logger,filename,append,pattern);}

#define GR_SET_FILE_APPENDER(name, filename, append, pattern) {         \
    gr::logger_ptr logger = gr::logger_get_logger(name);                \
    gr::logger_set_file_appender(logger,filename,append,pattern);}

#define GR_LOG_SET_FILE_APPENDER(logger, filename, append, pattern) {   \
    gr::logger_set_file_appender(logger,filename,append,pattern);}

#define GR_ADD_ROLLINGFILE_APPENDER(name, filename, filesize, bkup_index, append, mode, pattern) { \
    gr::logger_ptr logger = gr::logger_get_logger(name);                    \
    gr::logger_add_rollingfile_appender(logger,filename,filesize,bkup_index,append,mode,pattern);}

#define GR_LOG_ADD_ROLLINGFILE_APPENDER(logger, filename, filesize, bkup_index, append, mode, pattern) { \
    gr::logger_add_rollingfile_appender(logger,filename,filesize,bkup_index,append,mode,pattern);}

#define GR_GET_LOGGER_NAMES(names) {            \
    names = gr::logger_get_logger_names();}

#define GR_RESET_CONFIGURATION()                \
    gr::logger_config::reset_config();

  /* Logger name referenced macros */
#define GR_DEBUG(name, msg) {                                   \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::DEBUG << msg << log4cpp::eol;}

#define GR_INFO(name, msg) {                                    \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::INFO << msg << log4cpp::eol;}

#define GR_NOTICE(name, msg) {                                  \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger << log4cpp::Priority::NOTICE << msg;}

#define GR_WARN(name, msg) {                                    \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::WARN << msg << log4cpp::eol;}

#define GR_ERROR(name, msg) {                                   \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::ERROR << msg << log4cpp::eol;}

#define GR_CRIT(name, msg) {                                    \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::CRIT << msg << log4cpp::eol;}

#define GR_ALERT(name, msg) {                                   \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::ALERT << msg << log4cpp::eol;}

#define GR_FATAL(name, msg) {                                   \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::FATAL << msg << log4cpp::eol;}

#define GR_EMERG(name, msg) {                                   \
    gr::logger_ptr logger = gr::logger_get_logger(name);        \
    *logger<< log4cpp::Priority::EMERG << msg << log4cpp::eol;}

#define GR_ERRORIF(name, cond, msg) {                                   \
    if((cond)) {                                                        \
      gr::logger_ptr logger = gr::logger_get_logger(name);              \
      *logger<< log4cpp::Priority::ERROR << msg << log4cpp::eol;}       \
  }

#define GR_ASSERT(name, cond, msg) {                                    \
    if(!(cond)) {                                                       \
      gr::logger_ptr logger = gr::logger_get_logger(name);              \
      *logger<< log4cpp::Priority::EMERG << msg << log4cpp::eol;}       \
    assert(0);                                                          \
  }

  /* LoggerPtr Referenced Macros */
#define GR_LOG_DEBUG(logger, msg) {                                     \
    *logger << log4cpp::Priority::DEBUG << msg << log4cpp::eol;}

#define GR_LOG_INFO(logger, msg) {                              \
    *logger << log4cpp::Priority::INFO << msg << log4cpp::eol;}

#define GR_LOG_NOTICE(logger, msg) {                                    \
    *logger << log4cpp::Priority::NOTICE << msg << log4cpp::eol;}

#define GR_LOG_WARN(logger, msg) {                              \
    *logger << log4cpp::Priority::WARN << msg << log4cpp::eol;}

#define GR_LOG_ERROR(logger, msg) {                                     \
    *logger << log4cpp::Priority::ERROR << msg << log4cpp::eol;}

#define GR_LOG_CRIT(logger, msg) {                              \
    *logger << log4cpp::Priority::CRIT << msg << log4cpp::eol;}

#define GR_LOG_ALERT(logger, msg) {                                     \
    *logger << log4cpp::Priority::ALERT << msg << log4cpp::eol;}

#define GR_LOG_FATAL(logger, msg) {                                     \
    *logger << log4cpp::Priority::FATAL << msg << log4cpp::eol;}

#define GR_LOG_EMERG(logger, msg) {                                     \
    *logger << log4cpp::Priority::EMERG << msg << log4cpp::eol;}

#define GR_LOG_ERRORIF(logger,cond, msg) {                              \
    if((cond)) {                                                        \
      *logger<< log4cpp::Priority::ERROR << msg << log4cpp::eol;}       \
  }

#define GR_LOG_ASSERT(logger, cond, msg) {                       \
    if(!(cond)) {                                                \
      *logger<< log4cpp::Priority::EMERG << msg << log4cpp::eol; \
      assert(0);}                                                \
  }

namespace gr {

  /*!
   * \brief Class to control configuration of logger.
   * This is a singleton that can launch a thread to watch a config file for changes
   * \ingroup logging
   */
  class GR_RUNTIME_API logger_config
  {
  private:
    /*! \brief filename of logger config file */
    std::string filename;
    /*! \brief Period (seconds) over which watcher thread checks config file for changes */
    unsigned int watch_period;
    /*! \brief Pointer to watch thread for config file changes */
    boost::thread *watch_thread;

    /*! \brief Watcher thread method
     * /param filename Name of configuration file
     * /param watch_period Seconds between checks for changes in config file
     */
    static void watch_file(std::string filename,unsigned int watch_period);

    static bool logger_configured;

    logger_config()/*:
    rpc_get_filename("logger_config", "filename", &logger_config::get_filename4rpc,
      pmt::mp(""), pmt::mp(""), pmt::mp(""),
      "", "filename", RPC_PRIVLVL_MIN,
      DISPTIME | DISPOPTSTRIP),
    rpc_get_watchperiod("logger_config", "watch_period", &logger_config::get_watchperiod4rpc,
      pmt::mp(0), pmt::mp(32768), pmt::mp(0),
      "", "watch_period", RPC_PRIVLVL_MIN,
      DISPTIME | DISPOPTSTRIP),
    rpc_get_config("logger_config", "config", &logger_config::get_config4rpc,
      pmt::mp(""), pmt::mp(""), pmt::mp(""),
      "", "filename", RPC_PRIVLVL_MIN,
      DISPTIME | DISPOPTSTRIP),
    rpc_set_config("logger_config","config", &logger_config::set_config4rpc,
      pmt::mp(""), pmt::mp(""), pmt::mp(""),
      "", "filename", RPC_PRIVLVL_MIN,
      DISPTIME | DISPOPTSTRIP)
                   */
    {
    }  //!< Constructor

    /*
      rpcbasic_register_get<logger_config,std::string> rpc_get_filename;
      rpcbasic_register_get<logger_config,int> rpc_get_watchperiod;
      rpcbasic_register_get<logger_config,std::string> rpc_get_config;
      rpcbasic_register_set<logger_config,std::string> rpc_set_config;
    */

    logger_config(logger_config const&);  //!<Copy constructor
    void operator=(logger_config const&);  //!<Assignment Operator

    std::string get_filename4rpc() {
      return filename;
    }
    int get_watchperiod4rpc(){return watch_period;};

    std::string get_config4rpc() {
      return filename;
    }

    void set_config4rpc(std::string set) {
      printf("Set string was:%s\n", set.c_str());
    }

    /*! \brief destrcutor stops watch thread before exits */
    ~logger_config() {
      stop_watch();
    }

    /*! \brief Instance getter for singleton. Only used by class. */
    static logger_config& get_instance(void);

  public:
    /*! \brief Getter for config filename */
    static std::string get_filename();
    /*! \brief Getter for watch period */
    static unsigned int get_watch_period();
    /*! \brief Method to load configuration
     * /param filename Name of configuration file
     * /param watch_period Seconds between checks for changes in config file
     */
    static void load_config(std::string filename,unsigned int watch_period=0);
    /*! \brief Method to stop watcher thread */
    static void stop_watch();
    /*! \brief method to reset logger configuration */
    static void reset_config(void);
  };

  /*!
   * \brief Retrieve a pointer to a logger by name
   *
   * Retrieves a logger pointer
   * \p name.
   *
   * \param name Name of the logger for which a pointer is requested
   */
  GR_RUNTIME_API logger_ptr logger_get_logger(std::string name);

  /*!
   * \brief Load logger's configuration file.
   *
   * Initialize the GNU Radio logger by loading the configuration file
   * \p config_filename.
   *
   * \param config_filename The configuration file. Set to "" for the
   *        basic logger that outputs to the console.
   */
  GR_RUNTIME_API bool logger_load_config(const std::string &config_filename="");

  /*!
   * \brief Reset logger's configuration file.
   *
   * Remove all appenders from loggers
   */
  GR_RUNTIME_API void logger_reset_config(void);

  /*!
   * \brief Set the logger's output level.
   *
   * Sets the level of the logger. This takes a string that is
   * translated to the standard levels and can be (case insensitive):
   *
   * \li off , notset
   * \li debug
   * \li info
   * \li notice
   * \li warn
   * \li error
   * \li crit
   * \li alert
   * \li fatal
   * \li emerg
   *
   * \param logger the logger to set the level of.
   * \param level  string to set the level to.
   */
  GR_RUNTIME_API void logger_set_level(logger_ptr logger,
                                       const std::string &level);

  /*!
   * \brief Set the logger's output level.
   *
   * Sets the level of the logger. This takes the actual Log4cpp::Priority
   * data type, which can be:
   *
   * \li log4cpp::Priority::NOTSET
   * \li log4cpp::Priority::DEBUG
   * \li log4cpp::Priority::INFO
   * \li log4cpp::Priority::NOTICE
   * \li log4cpp::Priority::WARN
   * \li log4cpp::Priority::ERROR
   * \li log4cpp::Priority::CRIT
   * \li log4cpp::Priority::ALERT
   * \li log4cpp::Priority::FATAL
   * \li log4cpp::Priority::EMERG
   *
   * \param logger the logger to set the level of.
   * \param level  new logger level of type Log4cpp::Priority
   */
  GR_RUNTIME_API void logger_set_level(logger_ptr logger,
                                       log4cpp::Priority::Value level);

  /*!
   * \brief Get the logger's output level.
   *
   * Gets the level of the logger. This returns a string that
   * corresponds to the standard levels and can be (case insensitive):
   *
   * \li notset
   * \li debug
   * \li info
   * \li notice
   * \li warn
   * \li error
   * \li crit
   * \li alert
   * \li fatal
   * \li emerg
   *
   * \param logger the logger to get the level of.
   * \param level  string to get the level into.
   */
  GR_RUNTIME_API void logger_get_level(logger_ptr logger, std::string &level);

  /*!
   * \brief Get the logger's output level.
   *
   * Gets the level of the logger. This returns the actual Log4cpp::Level
   * data type, which can be:
   *
   * \li log4cpp::Priority::NOTSET
   * \li log4cpp::Priority::DEBUG
   * \li log4cpp::Priority::INFO
   * \li log4cpp::Priority::NOTICE
   * \li log4cpp::Priority::WARN
   * \li log4cpp::Priority::ERROR
   * \li log4cpp::Priority::CRIT
   * \li log4cpp::Priority::ALERT
   * \li log4cpp::Priority::FATAL
   * \li log4cpp::Priority::EMERG
   *
   * \param logger the logger to get the level of.
   * \param level of the logger.
   */
  GR_RUNTIME_API void logger_get_level(logger_ptr logger,
                                       log4cpp::Priority::Value &level);

  /*!
   * \brief Add console appender to a given logger
   *
   * Add console appender to a given logger
   *
   * \param logger Logger to which appender will be added
   * \param appender Name of appender to add to logger
   */
  GR_RUNTIME_API void logger_add_appender(logger_ptr logger,
                                          std::string appender);

  /*!
   * \brief Sets a console appender to a given logger. Deletes any
   * existing appenders and adds a new one. To add an additional
   * appender, use logger_add_appender.
   *
   * \param logger Logger to which appender will be added
   * \param appender Name of appender to add to logger
   */
  GR_RUNTIME_API void logger_set_appender(logger_ptr logger,
                                          std::string appender);

  /*!
   * \brief Add console appender to a given logger
   *
   * Add console appender to a given logger
   *
   * \param logger Logger to which appender will be added
   * \param target Std target to write 'cout' or 'cerr' (default is cout)
   * \param pattern Formatting pattern for log messages
   */
  GR_RUNTIME_API void logger_add_console_appender(logger_ptr logger,
                                                  std::string target,
                                                  std::string pattern);

  /*!
   * \brief Sets a new console appender to a given logger after
   * removing all others. Use logger_add_console_appender to add
   * another.
   *
   * \param logger Logger to which appender will be added
   * \param target Std target to write 'cout' or 'cerr' (default is cout)
   * \param pattern Formatting pattern for log messages
   */
  GR_RUNTIME_API void logger_set_console_appender(logger_ptr logger,
                                                  std::string target,
                                                  std::string pattern);

  /*!
   * \brief Add file appender to a given logger
   *
   * Add file appender to a given logger
   *
   * \param logger Logger to which appender will be added
   * \param filename File to which log will be written
   * \param append Overwrite or append to log file
   * \param pattern Formatting pattern for log messages
   */
  GR_RUNTIME_API void logger_add_file_appender(logger_ptr logger,
                                               std::string filename,
                                               bool append, std::string pattern);

  /*!
   * \brief Set a file appender to a given logger. To add another file
   * appender, use logger_add_file_appender.
   *
   * \param logger Logger to which appender will be added
   * \param filename File to which log will be written
   * \param append Overwrite or append to log file
   * \param pattern Formatting pattern for log messages
   */
  GR_RUNTIME_API void logger_set_file_appender(logger_ptr logger,
                                               std::string filename,
                                               bool append, std::string pattern);

  /*!
   * \brief Add rolling file appender to a given logger
   *
   * Add rolling file appender to a given logger
   *
   * \param logger Logger to which appender will be added
   * \param filename File to which log will be written
   * \param filesize Sizez of files to write
   * \param bkup_index Number of files to write
   * \param append Overwrite or append to log file
   * \param mode Permissions to set on log file
   * \param pattern Formatting pattern for log messages
   */
  GR_RUNTIME_API void logger_add_rollingfile_appender(logger_ptr logger, std::string filename,
                                                      size_t filesize, int bkup_index, bool append,
                                                      mode_t mode,std::string pattern);

  /*!
   * \brief Add rolling file appender to a given logger
   *
   * Add rolling file appender to a given logger
   *
   * \return vector of string names of loggers
   */
  GR_RUNTIME_API std::vector<std::string> logger_get_logger_names(void);

} /* namespace gr */

#endif /* HAVE_LOG4CPP */

  // If Logger disable do nothing
#else /* ENABLE_GR_LOG */

namespace gr {
  typedef void* logger_ptr;
} /* namespace gr */

#define GR_LOG_DECLARE_LOGPTR(logger)
#define GR_LOG_ASSIGN_LOGPTR(logger,name)
#define GR_CONFIG_LOGGER(config)
#define GR_CONFIG_AND_WATCH_LOGGER(config,period)
#define GR_LOG_GETLOGGER(logger, name)
#define GR_SET_LEVEL(name, level)
#define GR_LOG_SET_LEVEL(logger, level)
#define GR_GET_LEVEL(name, level)
#define GR_LOG_GET_LEVEL(logger, level)
#define GR_ADD_APPENDER(name,appender)
#define GR_LOG_ADD_APPENDER(logger,appender)
#define GR_SET_APPENDER(name,appender)
#define GR_LOG_SET_APPENDER(logger,appender)
#define GR_ADD_CONSOLE_APPENDER(logger,target,pattern)
#define GR_LOG_ADD_CONSOLE_APPENDER(logger,target,pattern)
#define GR_SET_CONSOLE_APPENDER(logger,target,pattern)
#define GR_LOG_SET_CONSOLE_APPENDER(logger,target,pattern)
#define GR_ADD_FILE_APPENDER(name,filename,append,pattern)
#define GR_LOG_ADD_FILE_APPENDER(logger,filename,append,pattern)
#define GR_SET_FILE_APPENDER(name,filename,append,pattern)
#define GR_LOG_SET_FILE_APPENDER(logger,filename,append,pattern)
#define GR_ADD_ROLLINGFILE_APPENDER(name,filename,filesize,bkup_index,append,mode,pattern)
#define GR_LOG_ADD_ROLLINGFILE_APPENDER(logger,filename,filesize,bkup_index,append,mode,pattern)
#define GR_GET_LOGGER_NAMES(names)
#define GR_RESET_CONFIGURATION()
#define GR_DEBUG(name, msg)
#define GR_INFO(name, msg)
#define GR_NOTICE(name, msg)
#define GR_WARN(name, msg)
#define GR_ERROR(name, msg)
#define GR_ALERT(name, msg)
#define GR_CRIT(name, msg)
#define GR_FATAL(name, msg)
#define GR_EMERG(name, msg)
#define GR_ERRORIF(name, cond, msg)
#define GR_ASSERT(name, cond, msg)
#define GR_LOG_DEBUG(logger, msg)
#define GR_LOG_INFO(logger, msg)
#define GR_LOG_NOTICE(logger, msg)
#define GR_LOG_WARN(logger, msg)
#define GR_LOG_ERROR(logger, msg)
#define GR_LOG_ALERT(logger, msg)
#define GR_LOG_CRIT(logger, msg)
#define GR_LOG_FATAL(logger, msg)
#define GR_LOG_EMERG(logger, msg)
#define GR_LOG_ERRORIF(logger, cond, msg)
#define GR_LOG_ASSERT(logger, cond, msg)

#endif /* ENABLE_GR_LOG */

namespace gr {

  // Even if logger is disabled we'll need for methods below to exist in python.
  // The macros these call will be disabled if ENABLE_GR_LOG is undefined

  /********************* Start  Classes and Methods for Python ******************/
  /*!
   * \brief Logger class for referencing loggers in python.  Not
   * needed in C++ (use macros) Wraps and manipulates loggers for
   * python as python has no macros
   * \ingroup logging
   *
   */
  class GR_RUNTIME_API logger
  {
  private:
    /*! \brief logger pointer to logger associated wiith this wrapper class */
    logger_ptr d_logger;
  public:
    /*!
     * \brief constructor Provide name of logger to associate with this class
     * \param logger_name Name of logger associated with class
     */
    logger(std::string logger_name) {
      GR_LOG_ASSIGN_LOGPTR(d_logger,logger_name);
    };

    /*! \brief Destructor */
    ~logger(){;}

    // Wrappers for logging macros
    /*! \brief inline function, wrapper to set the logger level */
    void set_level(std::string level){GR_LOG_SET_LEVEL(d_logger,level);}

    /*! \brief inline function, wrapper to get the logger level */
    void get_level(std::string &level){GR_LOG_GET_LEVEL(d_logger,level);}

    /*! \brief inline function, wrapper for LOG4CPP_DEBUG for DEBUG message */
    void debug(std::string msg){GR_LOG_DEBUG(d_logger,msg);};

    /*! \brief inline function, wrapper for LOG4CPP_INFO for INFO message */
    void info(std::string msg){GR_LOG_INFO(d_logger,msg);}

    /*! \brief inline function, wrapper for NOTICE message */
    void notice(std::string msg){GR_LOG_NOTICE(d_logger,msg);}

    /*! \brief inline function, wrapper for LOG4CPP_WARN for WARN message */
    void warn(std::string msg){GR_LOG_WARN(d_logger,msg);}

    /*! \brief inline function, wrapper for LOG4CPP_ERROR for ERROR message */
    void error(std::string msg){GR_LOG_ERROR(d_logger,msg);}

    /*! \brief inline function, wrapper for NOTICE message */
    void crit(std::string msg){GR_LOG_CRIT(d_logger,msg);}

    /*! \brief inline function, wrapper for ALERT message */
    void alert(std::string msg){GR_LOG_ALERT(d_logger,msg);}

    /*! \brief inline function, wrapper for FATAL message */
    void fatal(std::string msg){GR_LOG_FATAL(d_logger,msg);}

    /*! \brief inline function, wrapper for EMERG message */
    void emerg(std::string msg){GR_LOG_EMERG(d_logger,msg);}

    /*! \brief inline function, wrapper for LOG4CPP_ASSERT for conditional ERROR message */
    void errorIF(bool cond,std::string msg){GR_LOG_ERRORIF(d_logger,cond,msg);}

    /*! \brief inline function, wrapper for LOG4CPP_ASSERT for conditional ERROR message */
    void log_assert(bool cond,std::string msg){GR_LOG_ASSERT(d_logger,cond,msg);}

    /*! \brief inline function, Method to add appender to logger by
        name (define appender in conf file) */
    void add_appender(std::string appender) {
      GR_LOG_ADD_APPENDER(d_logger, appender);
    }

    /*! \brief inline function, Method to set an appender to logger by
        name (define appender in conf file) */
    void set_appender(std::string appender) {
      GR_LOG_SET_APPENDER(d_logger, appender);
    }

    /*! \brief inline function, Method to add console appender to logger */
    void add_console_appender(std::string target,std::string pattern) {
      GR_LOG_ADD_CONSOLE_APPENDER(d_logger, target, pattern);
    }

    /*! \brief inline function, Method to set a console appender to logger */
    void set_console_appender(std::string target,std::string pattern) {
      GR_LOG_SET_CONSOLE_APPENDER(d_logger, target, pattern);
    }

    /*! \brief inline function, Method to add file appender to logger */
    void add_file_appender(std::string filename, bool append, std::string pattern) {
      GR_LOG_ADD_FILE_APPENDER(d_logger, filename, append, pattern);
    }

    /*! \brief inline function, Method to set a file appender to logger */
    void set_file_appender(std::string filename, bool append, std::string pattern) {
      GR_LOG_SET_FILE_APPENDER(d_logger, filename, append, pattern);
    }

    /*! \brief inline function, Method to add rolling file appender to logger */
    void add_rollingfile_appender(std::string filename, size_t filesize,
                                  int bkup_index, bool append, mode_t mode,
                                  std::string pattern) {
      GR_LOG_ADD_ROLLINGFILE_APPENDER(d_logger,filename,filesize,
                                      bkup_index,append,mode,pattern);
    }
  };

} /* namespace gr */

/**************** Start Configuration Class and Methods for Python ************/
/*!
 * \brief Function to call configuration macro from python.
 *        Note: Configuration is only updated if filename or watch_period has changed.
 * \param config_filename  Name of configuration file
 * \param watch_period Seconds to wait between checking for changes in conf file.
 *        Watch_period defaults to 0 in which case the file is not watched for changes
 */
GR_RUNTIME_API void gr_logger_config(const std::string config_filename,
                                     unsigned int watch_period = 0);

/*!
 * \brief Function to return logger names to python
 * \return Vector of name strings
 *
 */
GR_RUNTIME_API std::vector<std::string> gr_logger_get_logger_names(void);

/*!
 * \brief Function to reset logger configuration from python
 *
 */
GR_RUNTIME_API void gr_logger_reset_config(void);


namespace gr {
  /*!
   * Function to use the GR prefs files to get and setup the two
   * default loggers defined there. The loggers are unique to the
   * class in which they are called, and we pass it the \p name to
   * identify where the log message originates from. For a GNU Radio
   * block, we use 'alias()' for this value, and this is set up for us
   * automatically in gr::block.
   */
  GR_RUNTIME_API bool configure_default_loggers(gr::logger_ptr &l, gr::logger_ptr &d,
                                                const std::string name);

  GR_RUNTIME_API bool update_logger_alias(const std::string &name, const std::string &alias);

} /* namespace gr */


#endif /* INCLUDED_GR_LOGGER_H */
