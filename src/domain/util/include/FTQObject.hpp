#pragma once

#include <ostream>
#include <string>

namespace ftq_domain {

class FTQObject {
  public:
	virtual bool equals(FTQObject *ftqObject) { return this == ftqObject; }

	virtual std::string toString() { return "To string not implemented"; }
};

} // namespace ftq_domain