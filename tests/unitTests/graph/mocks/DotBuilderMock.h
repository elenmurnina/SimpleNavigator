#ifndef DOT_BUILDER_MOCK_H
#define DOT_BUILDER_MOCK_H

#include "IDotBuilder.h"
#include "gmock.h"

class DotBuilderMock : public IDotBuilder {
public:
  ~DotBuilderMock() override = default;

  MOCK_METHOD(std::string, buildDotFromGraph, (IGraph const &graph),
              (const, noexcept, override));
};

#endif
