/******************************************************************************
4.9. Дано цілі числа h, т (0 < h ≤ 12, 0 ≤ т ≤ 59), що вказують момент часу: "h годин,
т хвилин". Визначити найменший час (число повних хвилин), який має пройти до того
моменту, коли годинна та хвилинна стрілки на циферблаті:
а) співпадуть;
б) розташуються перпендикулярно один до одного.
*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    //int h{}, m{};
    double h{}, m{}, h_grade{}, m_grade{}, intersection{};
    
    cout << "H ? ";
    cin >> h;
    cout << "m ? ";
    cin >> m;
    
    //m_grade = (360.0 / 60) * m;
    //h_grade = (360.0 / 12) * h + m_grade / 12.0;
    
    m_grade = (360.0 / (60 * 60)) * m * 60;
    h_grade = (360.0 / (12 * 60 * 60)) * (h * 60 * 60) + m_grade / 12.0;
    
    //intersection = (h_grade - m_grade) / (60.0 / 12);
    
    intersection = (h_grade - m_grade);
    
    if (intersection < 0.0) {
        intersection = (360.0 + intersection) / (60 / 12);
    }
    
    else intersection / (60.0 / 12);
    
    cout << h << " H\t" << h_grade << char(176) << endl;
    cout << m << " m\t" << m_grade << char(176) << endl;
    cout << intersection;

    return 0;
}