/// \file
/// Example model -- simple pipeline

#ifndef PIPE_ILA_H__
#define PIPE_ILA_H__

namespace ilang {

class InstrLvlAbs;
class Ila;

/// \brief the class to build a pipe's model
class SimplePipe {

public:
  static Ila BuildModel();

}; // class SimplePipe

/// \brief UndetExample
class UndetVal {
public:
  static Ila BuildModel();
};

/// \brief UndetExample -- function
class UndetFunc {
public:
  static Ila BuildModel();
  static Ila BuildIteUknModel();
};

/// \brief UndetExample -- building a monitor
class MonitorTest {
public:
  static Ila BuildModel();
};

/// \brief Counter -- just a counter
/// with a single instruction:
/// INC c <= c + 1
class CntTest {
public:
  static Ila BuildModel();
};

}; // namespace ilang


#endif // PIPE_ILA_H__
