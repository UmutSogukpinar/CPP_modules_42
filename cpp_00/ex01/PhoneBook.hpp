#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook 
{
    private:

        // Fields
        Contact     contacts_[8];
        int         index_;

        // Methods
        int			getProperIndex();

    public:

        // Constructor
        PhoneBook();

        // Methods
        Contact		getContact(int index);
        void        Add(const std::string fields[5]);

};



#endif
