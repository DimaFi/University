using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text.RegularExpressions;
using System.Xml.Linq;
using System.Xml.Serialization;


namespace pr18_19_gl1_6
{
    public class Program
    {
        static void Main()
        {
            List<Product> products = new List<Product>(); // Список со всеми продуктами
            BinaryFormatter formatter = new BinaryFormatter();
            //XmlSerializer formatter = new XmlSerializer(typeof(Product));
            //SoapFormatter formatter = new SoapFormatter();


            if (!File.Exists("product.xml") || new FileInfo("product.xml").Length == 0)
            {
                products = LoadProductsFromFile("products.txt"); // Список продуктов
            }
            else
            {
                using (FileStream fin = new FileStream("product.xml", FileMode.Open))
                {
                    products.Add((Product)formatter.Deserialize(fin));
                }
            }
            PrintProducts(products); // Выводим всю инфу о продуктах

            DateTime currentDate = DateTime.Now;
            var expiredProducts = products.FindAll(product => product.IsExpired(currentDate.ToString("yyyy-MM-dd"))); // Массив просрочки

            //сериализация
            using (FileStream fout = new FileStream("product.xml", FileMode.OpenOrCreate, FileAccess.Write, FileShare.None)) //.dat
            {
                formatter.Serialize(fout, products[0]);
                fout.Close();
            }

            Console.WriteLine("-------------------");
            Console.WriteLine("Просрочка:");
            Console.WriteLine();

            PrintProducts(expiredProducts);
            Console.WriteLine();

            Console.WriteLine("-------------------");
            Console.WriteLine("Отсортированные продукты:");
            Console.WriteLine();

            products.Sort();
            PrintProducts(products);
            Console.WriteLine("-------------------");
        }

        static void PrintProducts(List<Product> products)
        {
            foreach (var product in products)
            {
                Console.WriteLine(product);
                Console.WriteLine();
            }
        }

        static List<Product> LoadProductsFromFile(string filePath)
        {
            List<Product> products = new List<Product>();
            //BinaryFormatter formatter = new BinaryFormatter();
            XmlSerializer formatter = new XmlSerializer(typeof(Product));

            string[] lines = File.ReadAllLines(filePath);

            foreach (string line in lines)
            {
                string[] data = line.Split(',');

                string productType = data[0];
                string name = data[1];
                int price = Convert.ToInt32(data[2]);

                switch (productType)
                {
                    case "Element":
                        string productionDate = data[3];
                        string expiryDate = data[4];
                        products.Add(new Element(name, price, productionDate, expiryDate));
                        break;

                    case "Batch":
                        int quantity = Convert.ToInt32(data[3]);
                        productionDate = data[4];
                        expiryDate = data[5];
                        products.Add(new Batch(name, price, quantity, productionDate, expiryDate));
                        break;

                    case "Set":
                        Set set = new Set(name, price); // создаём экземпляр класса сет и добавляем элементы в его лист
                        set.Products = new List<Product>();

                        for (int i = 3; i < data.Length; i += 4)
                        {
                            Element prod1 = new Element(data[i], Convert.ToInt32(data[i + 1]), data[i + 2], data[i + 3]);
                            set.Products.Add(prod1);
                        }

                        products.Add(set);

                        break;
                }
            }
            return products;
        }
    }
}
