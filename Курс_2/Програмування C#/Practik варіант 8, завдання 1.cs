/*
513-і Золотухін Андрій, варіант 8, завдання 1:
Створити абстрактний клас Triangle (трикутник), задавши в ньому довжину двох сторін, кут між ними, методи обчислення площі та периметра. На його основі створити класи, що описують рівносторонній, рівнобедрений і прямокутний трикутники зі своїми методами обчислення площі та периметра. 
*/

using System;

// Абстрактний клас "Трикутник"
abstract class Triangle
{
    protected double sideA;           // Сторона A
    protected double sideB;           // Сторона B
    protected double angleDegrees;    // Кут між сторонами в градусах

    public Triangle(double sideA, double sideB, double angleDegrees)
    {
        this.sideA = sideA;
        this.sideB = sideB;
        this.angleDegrees = angleDegrees;
    }

    // Абстрактний метод для обчислення периметра
    public abstract double GetPerimeter();

    // Абстрактний метод для обчислення площі
    public abstract double GetArea();
}

// Рівносторонній трикутник
class EquilateralTriangle : Triangle
{
    public EquilateralTriangle(double side) : base(side, side, 60) { }

    // Периметр рівностороннього трикутника
    public override double GetPerimeter()
    {
        return 3 * sideA;
    }

    // Площа рівностороннього трикутника
    public override double GetArea()
    {
        return (Math.Sqrt(3) / 4) * sideA * sideA;
    }
}

// Рівнобедрений трикутник
class IsoscelesTriangle : Triangle
{
    public IsoscelesTriangle(double equalSide, double angleBetweenEqualSides)
        : base(equalSide, equalSide, angleBetweenEqualSides) { }

    // Периметр рівнобедреного трикутника
    public override double GetPerimeter()
    {
        double angleRadians = angleDegrees * Math.PI / 180;
        // Знаходимо третю сторону за теоремою косинусів
        double baseSide = Math.Sqrt(2 * sideA * sideA - 2 * sideA * sideA * Math.Cos(angleRadians));
        return 2 * sideA + baseSide;
    }

    // Площа рівнобедреного трикутника
    public override double GetArea()
    {
        double angleRadians = angleDegrees * Math.PI / 180;
        return 0.5 * sideA * sideB * Math.Sin(angleRadians);
    }
}

// Прямокутний трикутник
class RightTriangle : Triangle
{
    public RightTriangle(double legA, double legB)
        : base(legA, legB, 90) { }

    // Периметр прямокутного трикутника
    public override double GetPerimeter()
    {
        // Обчислюємо гіпотенузу за теоремою Піфагора
        double hypotenuse = Math.Sqrt(sideA * sideA + sideB * sideB);
        return sideA + sideB + hypotenuse;
    }

    // Площа прямокутного трикутника
    public override double GetArea()
    {
        return 0.5 * sideA * sideB;
    }
}

// Тестова програма
class Program
{
    static void Main()
    {
        // Рівносторонній трикутник зі стороною 5
        Triangle t1 = new EquilateralTriangle(5);
        Console.WriteLine("Рівносторонній трикутник:");
        Console.WriteLine($"Площа: {t1.GetArea():F2}, Периметр: {t1.GetPerimeter():F2}");

        // Рівнобедрений трикутник зі сторонами 5 і кутом 45°
        Triangle t2 = new IsoscelesTriangle(5, 45);
        Console.WriteLine("\nРівнобедрений трикутник:");
        Console.WriteLine($"Площа: {t2.GetArea():F2}, Периметр: {t2.GetPerimeter():F2}");

        // Прямокутний трикутник з катетами 3 і 4
        Triangle t3 = new RightTriangle(3, 4);
        Console.WriteLine("\nПрямокутний трикутник:");
        Console.WriteLine($"Площа: {t3.GetArea():F2}, Периметр: {t3.GetPerimeter():F2}");
    }
}
