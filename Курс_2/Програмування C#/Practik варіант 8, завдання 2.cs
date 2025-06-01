/*
513-і Золотухін Андрій, варіант 8, завдання 2:
Створити клас Picture, що містить масив/параметризовану колекцію об'єктів цих класів у динамічній пам'яті. Передбачити можливість виведення характеристик об'єктів списку та отримання сумарної площі. Написати демонстраційну програму, в якій будуть використовуватися всі методи класів. 
*/

using System;
using System.Collections.Generic;

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
    public abstract string GetDescription(); // Метод для опису трикутника
}

// Рівносторонній трикутник
class EquilateralTriangle : Triangle
{
    public EquilateralTriangle(double side) : base(side, side, 60) { }

    public override double GetPerimeter()
    {
        return 3 * sideA;
    }

    public override double GetArea()
    {
        return (Math.Sqrt(3) / 4) * sideA * sideA;
    }

    public override string GetDescription()
    {
        return $"Рівносторонній трикутник (сторона = {sideA})";
    }
}

// Рівнобедрений трикутник
class IsoscelesTriangle : Triangle
{
    public IsoscelesTriangle(double equalSide, double angleBetweenEqualSides)
        : base(equalSide, equalSide, angleBetweenEqualSides) { }

    public override double GetPerimeter()
    {
        double angleRadians = angleDegrees * Math.PI / 180;
        double baseSide = Math.Sqrt(2 * sideA * sideA - 2 * sideA * sideA * Math.Cos(angleRadians));
        return 2 * sideA + baseSide;
    }

    public override double GetArea()
    {
        double angleRadians = angleDegrees * Math.PI / 180;
        return 0.5 * sideA * sideB * Math.Sin(angleRadians);
    }

    public override string GetDescription()
    {
        return $"Рівнобедрений трикутник (сторони = {sideA}, кут = {angleDegrees}°)";
    }
}

// Прямокутний трикутник
class RightTriangle : Triangle
{
    public RightTriangle(double legA, double legB)
        : base(legA, legB, 90) { }

    public override double GetPerimeter()
    {
        double hypotenuse = Math.Sqrt(sideA * sideA + sideB * sideB);
        return sideA + sideB + hypotenuse;
    }

    public override double GetArea()
    {
        return 0.5 * sideA * sideB;
    }

    public override string GetDescription()
    {
        return $"Прямокутний трикутник (катети = {sideA}, {sideB})";
    }
}

// Клас Picture — зберігає список трикутників
class Picture
{
    private List<Triangle> triangles; // Колекція трикутників

    public Picture()
    {
        triangles = new List<Triangle>();
    }

    // Додати трикутник до колекції
    public void AddTriangle(Triangle triangle)
    {
        triangles.Add(triangle);
    }

    // Вивести характеристики всіх трикутників
    public void PrintAll()
    {
        Console.WriteLine("Список трикутників:");
        foreach (var triangle in triangles)
        {
            Console.WriteLine($"{triangle.GetDescription()}");
            Console.WriteLine($"  → Площа: {triangle.GetArea():F2}, Периметр: {triangle.GetPerimeter():F2}\n");
        }
    }

    // Отримати сумарну площу всіх трикутників
    public double GetTotalArea()
    {
        double total = 0;
        foreach (var triangle in triangles)
        {
            total += triangle.GetArea();
        }
        return total;
    }
}

// Демонстраційна програма
class Program
{
    static void Main()
    {
        // Створюємо об'єкт Picture
        Picture picture = new Picture();

        // Додаємо різні трикутники
        picture.AddTriangle(new EquilateralTriangle(6));
        picture.AddTriangle(new IsoscelesTriangle(5, 45));
        picture.AddTriangle(new RightTriangle(3, 4));

        // Виводимо всі характеристики
        picture.PrintAll();

        // Виводимо сумарну площу
        Console.WriteLine($"Сумарна площа всіх трикутників: {picture.GetTotalArea():F2}");
    }
}

