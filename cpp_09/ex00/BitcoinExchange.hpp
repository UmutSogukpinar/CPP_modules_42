#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <fstream>

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
            bool isValidDate(int year, int month, int day) const;

        public:
            // ============= Constructors and Destructor =============

            Date();
            Date(std::string dateStr, float value);
            ~Date();

            // ============= Getters =============

            int getYear() const;
            int getMonth() const;
            int getDay() const;
            const std::string &getDateStr() const;
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
        float getRateForDate(const std::string &dateStr);

    public:
        // ============= Constructors and Destructor =============

        BitcoinExchange();
        BitcoinExchange(std::ifstream *file);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
};

#endif
