using System;
using System.Text;

namespace Des_algorithm
{
    public class DESAlgorithm
    {
        private const int sizeOfBlock = 128;
        private const int shiftKey = 2;
        private const int quantityOfRounds = 16;

        public string[] Blocks;

        public string StringToRightLength(string input)
        {
            int sizeOfChar = 16; // Локальная переменная sizeOfChar
            while (((input.Length * sizeOfChar) % sizeOfBlock) != 0)
                input += "#";
            return input;
        }

        public void CutStringIntoBlocks(string input)
        {
            Blocks = new string[(input.Length * 16) / sizeOfBlock];
            int lengthOfBlock = input.Length / Blocks.Length;
            for (int i = 0; i < Blocks.Length; i++)
            {
                Blocks[i] = input.Substring(i * lengthOfBlock, lengthOfBlock);
                Blocks[i] = StringToBinaryFormat(Blocks[i]);
            }
        }

        private string StringToBinaryFormat(string input)
        {
            StringBuilder output = new StringBuilder();
            foreach (char c in input)
            {
                string char_binary = Convert.ToString(c, 2).PadLeft(8, '0');
                output.Append(char_binary);
            }
            return output.ToString();
        }

        public void CutBinaryStringIntoBlocks(string input)   // нужно приватность
        {
            Blocks = new string[input.Length / sizeOfBlock];
            int lengthOfBlock = input.Length / Blocks.Length;
            for (int i = 0; i < Blocks.Length; i++)
                Blocks[i] = input.Substring(i * lengthOfBlock, lengthOfBlock);
        }


        private string CorrectKeyWord(string input, int lengthKey)
        {
            if (input.Length > lengthKey)
                input = input.Substring(0, lengthKey);
            else
                while (input.Length < lengthKey)
                    input = "0" + input;
            return input;
        }

        public string EncodeDES_One_Round(string input, string key)
        {
            string L = input.Substring(0, input.Length / 2);
            string R = input.Substring(input.Length / 2, input.Length / 2);
            return (R + XOR(L, f(R, key)));
        }

        public string DecodeDES_One_Round(string input, string key)
        {
            string L = input.Substring(0, input.Length / 2);
            string R = input.Substring(input.Length / 2, input.Length / 2);
            return (R + XOR(f(L, key), R));
        }

        private static string XOR(string s1, string s2)
        {
            int maxLength = Math.Max(s1.Length, s2.Length);
            s1 = s1.PadLeft(maxLength, '0');
            s2 = s2.PadLeft(maxLength, '0');

            StringBuilder result = new StringBuilder();
            for (int i = 0; i < maxLength; i++)
            {
                if (s1[i] == '1' ^ s2[i] == '1')
                    result.Append("1");
                else
                    result.Append("0");
            }
            return result.ToString();
        }

        public string TestXOR(string s1, string s2, string expected)
        {
            string result = XOR(s1, s2);

            if (result == expected)
            {
                return "Проверка пройдена успешно!";
            }
            else
            {
                return "Ошибка в методе XOR.";
            }
        }

        private string f(string s1, string s2)
        {
            return XOR(s1, s2);
        }

        private string KeyToNextRound(string key)
        {
            for (int i = 0; i < shiftKey; i++)
            {
                key = key[key.Length - 1] + key;
                key = key.Remove(key.Length - 1);
            }
            return key;
        }

        private string KeyToPrevRound(string key)
        {
            for (int i = 0; i < shiftKey; i++)
            {
                key = key + key[0];
                key = key.Remove(0, 1);
            }
            return key;
        }

    }
    public static class StringUtils
    {
        public static string StringFromBinaryToNormalFormat(string input, int sizeOfChar)
        {
            StringBuilder output = new StringBuilder();
            int length = input.Length;
            for (int i = 0; i < length; i += sizeOfChar)
            {
                // Проверяем, осталось ли достаточно символов для создания нового символа
                if (i + sizeOfChar <= length)
                {
                    string char_binary = input.Substring(i, sizeOfChar);
                    int charCode = Convert.ToInt32(char_binary, 2);
                    output.Append((char)charCode);
                }
                else
                {
                    // Если не хватает символов, прекращаем итерацию
                    break;
                }
            }
            return output.ToString();
        }
    }

    internal class Program
    {
        public static void Main(string[] args)
        {
            string input = "Hello, world!";
            string key = "secret12";

            if (key.Length != 8)
            {
                Console.WriteLine("Ошибка: ключ должен быть 8 символов длиной.");
                return;
            }

            DESAlgorithm des = new DESAlgorithm();
            input = des.StringToRightLength(input);
            des.CutStringIntoBlocks(input);

            // Шифрование
            string encryptedData = "";
            foreach (var block in des.Blocks)
            {
                encryptedData += des.EncodeDES_One_Round(block, key);
            }
            Console.WriteLine("Зашифрованные данные: " + encryptedData);

            // Расшифрование
            string decryptedData = "";
            foreach (var block in des.Blocks)
            {
                decryptedData += des.DecodeDES_One_Round(block, key);
            }

            int sizeOfChar = 16; // Получаем значение sizeOfChar из какого-то другого места или задаем явно

            Console.WriteLine("Расшифрованные данные:");
            Console.WriteLine(StringUtils.StringFromBinaryToNormalFormat(decryptedData, sizeOfChar));

            string testResult = des.TestXOR("0110", "1010", "1100");
            Console.WriteLine("Результат теста XOR: " + testResult);

        }
    }
}
