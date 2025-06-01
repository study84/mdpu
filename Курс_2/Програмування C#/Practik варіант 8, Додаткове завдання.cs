/*
513-і Золотухін Андрій, варіант 8, завдання 2:
Додаткове завдання: доповнити клас методами сортування за деяким критерієм, виведення у файл і зчитування з файлу.
*/

using System;
using System.Collections.Generic;
using System.IO;

// Абстрактний клас "Трикутник"
abstract class Triangle
{
    protected double sideA;
    protected double sideB;
    protected double angleDegrees;

    public Triangle(double sideA, double sideB, double angleDegrees)
    {
        this.sideA = sideA;
        this.sideB = sideB;
        this.angleDegrees = angleDegrees;
    }

    public abstract double GetPerimeter();
    public abstract double GetArea();
    public abstract string GetDescription();
    public abstract string Serialize(); // Для збереження у файл

    // Фабрика для створення трикутника з рядка
    public static Triangle Deserialize(string line)
    {
        var parts = line.Split(',');

        string type = parts[0];

        if (type == "Equilateral")
        {
            double side = double.Parse(parts[1]);
            return new EquilateralTriangle(side);
        }
        else if (type == "Isosceles")
        {
            double side = double.Parse(parts[1]);
            double angle = double.Parse(parts[2]);
            return new IsoscelesTriangle(side, angle);
        }
        else if (type == "Right")
        {
            double legA = double.Parse(parts[1]);
            double legB = double.Parse(parts[2]);
            return new RightTriangle(legA, legB);
        }

        throw new Exception("Невідомий тип трикутника.");
    }
}

// Рівносторонній
class EquilateralTriangle : Triangle
{
    public EquilateralTriangle(double side) : base(side, side, 60) { }

    public override double GetPerimeter() => 3 * sideA;
    public override double GetArea() => (Math.Sqrt(3) / 4) * sideA * sideA;

    public override string GetDescription() => $"Рівносторонній трикутник (сторона = {sideA})";
    public override string Serialize() => $"Equilateral,{sideA}";
}

// Рівнобедрений
class IsoscelesTriangle : Triangle
{
    public IsoscelesTriangle(double equalSide, double angleBetweenEqualSides)
        : base(equalSide, equalSide, angleBetweenEqualSides) { }

    public override double GetPerimeter()
    {
        double angleRad = angleDegrees * Math.PI / 180;
        double baseSide = Math.Sqrt(2 * sideA * sideA - 2 * sideA * sideA * Math.Cos(angleRad));
        return 2 * sideA + baseSide;
    }

    public override double GetArea()
    {
        double angleRad = angleDegrees * Math.PI / 180;
        return 0.5 * sideA * sideB * Math.Sin(angleRad);
    }

    public override string GetDescription()
        => $"Рівнобедрений трикутник (сторони = {sideA}, кут = {angleDegrees}°)";

    public override string Serialize() => $"Isosceles,{sideA},{angleDegrees}";
}

// Прямокутний
class RightTriangle : Triangle
{
    public RightTriangle(double legA, double legB)
        : base(legA, legB, 90) { }

    public override double GetPerimeter()
    {
        double hypotenuse = Math.Sqrt(sideA * sideA + sideB * sideB);
        return sideA + sideB + hypotenuse;
    }

    public override double GetArea() => 0.5 * sideA * sideB;

    public override string GetDescription()
        => $"Прямокутний трикутник (катети = {sideA}, {sideB})";

    public override string Serialize() => $"Right,{sideA},{sideB}";
}

// Клас Picture з розширеним функціоналом
class Picture
{
    private List<Triangle> triangles = new List<Triangle>();

    public void AddTriangle(Triangle triangle) => triangles.Add(triangle);

    public void PrintAll()
    {
        Console.WriteLine("Список трикутників:");
        foreach (var t in triangles)
        {
            Console.WriteLine($"{t.GetDescription()}");
            Console.WriteLine($"  → Площа: {t.GetArea():F2}, Периметр: {t.GetPerimeter():F2}\n");
        }
    }

    public double GetTotalArea()
    {
        double sum = 0;
        foreach (var t in triangles)
            sum += t.GetArea();
        return sum;
    }

    // Сортування за площею
    public void SortByArea()
    {
        triangles.Sort((t1, t2) => t1.GetArea().CompareTo(t2.GetArea()));
    }

    // Сортування за периметром
    public void SortByPerimeter()
    {
        triangles.Sort((t1, t2) => t1.GetPerimeter().CompareTo(t2.GetPerimeter()));
    }

    // Запис у файл
    public void SaveToFile(string filename)
    {
        using (StreamWriter writer = new StreamWriter(filename))
        {
            foreach (var t in triangles)
            {
                writer.WriteLine(t.Serialize());
            }
        }
    }

    // Зчитування з файлу
    public void LoadFromFile(string filename)
    {
        triangles.Clear();
        if (!File.Exists(filename))
        {
            Console.WriteLine("Файл не знайдено.");
            return;
        }

        var lines = File.ReadAllLines(filename);
        foreach (var line in lines)
        {
            triangles.Add(Triangle.Deserialize(line));
        }
    }
}

// Демонстраційна програма
class Program
{
    static void Main()
    {
        Picture picture = new Picture();

        // Додаємо фігури
        picture.AddTriangle(new EquilateralTriangle(6));
        picture.AddTriangle(new IsoscelesTriangle(5, 45));
        picture.AddTriangle(new RightTriangle(3, 4));

        Console.WriteLine("➤ Початковий список:");
        picture.PrintAll();

        // Сортування за площею
        picture.SortByArea();
        Console.WriteLine("➤ Відсортовано за площею:");
        picture.PrintAll();

        // Запис у файл
        string filePath = "triangles.txt";
        picture.SaveToFile(filePath);
        Console.WriteLine($"➤ Дані збережено у файл: {filePath}");

        // Новий об'єкт для перевірки зчитування
        Picture loadedPicture = new Picture();
        loadedPicture.LoadFromFile(filePath);

        Console.WriteLine("➤ Завантажено з файлу:");
        loadedPicture.PrintAll();
    }
}

