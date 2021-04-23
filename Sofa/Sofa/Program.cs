using System;
using System.Collections.Generic;
using System.Text;

namespace Furniture
{
    class Program
    {
        static void Main()
        {
            Sofa sofa = new Sofa();
            sofa.colour = "красный";
            sofa.upholstery = "мягкая";
            int year;
            try
            {
                Console.Write("Введите сколько слушит вам диван - ");
                year = Convert.ToInt32(Console.ReadLine());
                sofa.SetYear(year);
            }
            catch(FormatException e)
            {
                Console.WriteLine("Не число!");
                Console.WriteLine(e.Message);
            }
            catch (OverflowException e)
            {
                Console.WriteLine("Слишком большое число");
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine("ОШИБКА!!!");
                Console.WriteLine(e.Message);
            }

            int legs;
            try
            {
                Console.Write("Введите сколько ножек у дивана - ");
                legs = Convert.ToInt32(Console.ReadLine());
                sofa.SetLegs(legs);
            }
            catch (FormatException e)
            {
                Console.WriteLine("Не число!");
                Console.WriteLine(e.Message);
            }
            catch (OverflowException e)
            {
                Console.WriteLine("Слишком большое число");
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine("ОШИБКА!!!");
                Console.WriteLine(e.Message);
            }

            int backrest;
            try
            {
                Console.Write("Введите 1 если у дивана есть спинка - ");
                backrest = Convert.ToInt32(Console.ReadLine());
                sofa.SetBackrest(backrest);
            }
            catch (FormatException e)
            {
                Console.WriteLine("Не число!");
                Console.WriteLine(e.Message);
            }
            catch (OverflowException e)
            {
                Console.WriteLine("Слишком большое число");
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine("ОШИБКА!!!");
                Console.WriteLine(e.Message);
            }

        }
     }
}
