//
// Created by survari on 06.11.16.
//

#ifndef TEST_INTEGER_HPP
#define TEST_INTEGER_HPP


class Integer
{
private:
    long value = 0;
    std::string name;
    bool isw = true;

public:
    int getIntValue()
    {
        return value;
    }

    std::string getName()
    {
        return name;
    }

    bool isWriteAble()
    {
        return isw;
    }

    void setIntValue(long val)
    {
        // std::cout << "\nVAR -> " << val << std::endl;
        // std::cout << "VAL -> " << value << std::endl;

        if (isWriteAble())
            value = val;
        else
            std::cout << "[ MAIN ]:[ SYS ]:[ INTEGER ]:[ VARIABLE_NOT_WRITEABLE:" << name << " ] Variable ist nicht beschreibbar!"
                      << std::endl;

        // std::cout << "NOW -> " << value << std::endl;
        // std::cout << "NAM -> " << name << std::endl << std::endl;
    }

    void setName(std::string n)
    {
        name = n;
    }

    void setWriteAble(bool b)
    {
        isw = b;
    }
};


#endif //TEST_INTEGER_HPP
