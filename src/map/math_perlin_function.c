/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

double fade(double t)
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}

static double get_u(int h, double x, double y)
{
    return (h < 8) ? x : y;
}

static double get_v(int h, double x, double y)
{
    double to_return = 0.0;

    if (h < 4)
        to_return = y;
    else if (h == 12 || h == 14)
        to_return = x;
    return to_return;
}

double grad(int hash, double x, double y)
{
    int h = hash & 15;
    double u = get_u(h, x, y);
    double v = get_v(h, x, y);

    return ((h & 1 ? -1 : 1) * (u + v));
}

double lerp(double t, double a, double b)
{
    return a + t * (b - a);
}
