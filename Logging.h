#ifndef LOGGING_H
#define LOGGING_H

#ifdef TANGO_LOG
  // cppTango after c934adea (Merge branch 'remove-cout-definition' into 'main', 2022-05-23)
  // nothing to do
#else
  // cppTango 9.3-backports and older
  #define TANGO_LOG       cout
  #define TANGO_LOG_INFO  cout2
  #define TANGO_LOG_DEBUG cout3
#endif // TANGO_LOG

#endif // LOGGING_H
