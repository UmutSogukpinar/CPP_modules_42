#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "string"
# include "map"

class BitcoinExchange
{
    class Date
    {
        private:
            int year_;
            int month_;
            int day_;
            std::string dateStr_;
            float value_;

            // ============= Private Methods =============

            void parseDate(const std::string &dateStr);
        

        public:

        // ============= Constructors and Destructor =============

            // Default Constructor
            Date();

            // Parameterized Constructor
            Date(std::string dateStr, float value_);

            // Destructor
            ~Date();

        // ============= Getters =============

            int getYear() const;
            int getMonth() const;
            int getDay() const;
            std::string &getDateStr() const;
            float getValue() const;

        // ============= Setters =============

            void setYear(int year);
            void setMonth(int month);
            void setDay(int day);
            void setDateStr(const std::string &dateStr);
            void setValue(float value);

        // ============= Other Member Functions =============

            bool isValid() const;
            bool isLeapYear() const;

    };

    private:
        std::ifstream *file_;
        std::map<std::string, Date> exchangeRates_;

        // ============= Private Member Functions =============

        void loadExchangeRates();
        void processInputFile();

    public:

        // ============= Constructors and Destructor =============

        // Default Constructor
        BitcoinExchange();

        // Parameterized Constructor
        BitcoinExchange(std::ifstream *file);

        // Copy Constructor
        BitcoinExchange(const BitcoinExchange& other);

        // Copy Assignment Operator
        BitcoinExchange& operator=(const BitcoinExchange& other);

        // Destructor
        ~BitcoinExchange();

        // ============= Other Member Functions =============


    
};


#endif