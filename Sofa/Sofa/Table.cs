using System;
using System.Collections.Generic;
using System.Text;

namespace Furniture
{
    public class Table
    {
        public string shape; //форма
        public string material;//материал
        private int _legs; //ножки
        private int _backrest; //спинка
        private int _year;//срок службы

        public void SetYear(int year)
        {
            if (year < 0 || year > 30)
            {
                throw new Exception("Столы обычно столько не служат!");
            }
            _year = year;
        }
        public int GetYear()
        {
            return _year;
        }

        public void SetLegs(int legs)
        {
            if (legs < 4)
            {
                throw new Exception("Стол не устойчив!");
            }
            if (legs > 4)
            {
                throw new Exception("Это какая-то многоножка!");
            }
            _legs = legs;
        }

        public int GetLegs()
        {
            return _legs;
        }

        public void SetBackrest(int backrest)
        {
            if (backrest > 0)
            {
                throw new Exception("Это не стол");
            }
            _backrest = backrest;
        }

        public int GetBackrest()
        {
            return _backrest;
        }
    }
}
