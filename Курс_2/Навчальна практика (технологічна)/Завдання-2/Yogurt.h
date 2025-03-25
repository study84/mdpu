#pragma once
#include "Product.h"

typedef unsigned short ushort;

class Yogurt :
    public Product
    {
        public:
            string flavor;
            string brand;

        private:
            ushort expiration_date;

        public:
            Yogurt();
            Yogurt(string brand, string flavor, string date);
            Yogurt(string name, float price, ushort amount, string brand, string flavor, string date = "2025-01-01");
            bool setDate(string date);
            string getDate();
            string info();
            bool usable(string date); // придатний для вживання

        private:
            bool isLeapYear(const ushort year);
            bool validator(const string str);
            ushort date_convert(const string date);
            string date_convert(const ushort date);
            

    };

