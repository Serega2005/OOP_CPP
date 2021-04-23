using System;

namespace Furniture
{
    public class Sofa
    {
        public string colour; //цвет
        public string upholstery; //оббивка
        private int _legs; //ножки
        private int _backrest; //спинка
        private int _year;//срок службы

        public void SetYear(int year)
        {
            if (year < 0 || year > 30)
            {
                throw new Exception("Диваны обычно столько не служат!");
            }
            _year = year;
        }
        public int GetYear()
        {
            return _year;
        }

        public void SetLegs(int legs)
        {
            if (legs < 4 )
            {
                throw new Exception("Диван не устойчив!");
            }
            if (legs > 4)
            {
                throw new Exception("Это какаято многоножка!");
            }
            _legs = legs;
        }

        public int GetLegs()
        {
            return _legs;
        }

        public void SetBackrest(int backrest)
        {
            if (backrest < 0 || backrest > 1)
            {
                throw new Exception("Это табуретка!)");
            }
            _backrest = backrest;
        }

        public int GetBackrest()
        {
            return _backrest;
        }

    }
}
