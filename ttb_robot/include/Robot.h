#pragma once

namespace ttb
{

class Robot
{
  public:
	virtual ~Robot();
	static Robot *get(); /**< Singleton Getter */
  private:
	Robot();
};

} /* namespace ttb */
