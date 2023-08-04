

#ifndef SDDS_Text_H
#define SDDS_Text_H

namespace sdds {
    class Text
    {
    private:
        char* m_content{};

    protected:
        const char& operator[](int index) const;

    public:
        Text();

        ~Text();
        Text(const Text&);
        Text& operator=(const Text&);

        unsigned getFileLength(std::istream&);

        std::istream& read(std::istream&);
        virtual std::ostream& write(std::ostream&) const;


        friend std::istream& operator>>(std::istream&, Text&);
        friend std::ostream& operator<<(std::ostream&, const Text&);
    };

}
#endif