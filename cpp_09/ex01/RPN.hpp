#ifndef RPN_HPP
# define RPN_HPP

# include "queue"
# include "stack"
# include "string"

class RPN
{
	private:
		std::queue<std::string> strQueue_;
		std::stack<int> numStack_;

		// ============== Private Functions ==============

		void processStack();
		void processCalculations(char opt);

	public:

		// ================= Constructors & Destructor =================

		// Default Constructor
		RPN();

		// Parameterized Constructor
		RPN(std::queue<std::string> strStack);

		// Destructor
		~RPN();

		// Copy Constructor
		RPN(const RPN &other);

		// Assignment Operator
		RPN &operator=(const RPN &other);

};

#endif