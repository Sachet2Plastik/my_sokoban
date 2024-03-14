/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** return 1 if given number is prime or else 0
*/

int my_is_prime(int nb)
{
    int i;
    int div;

    div = nb / 2;
    if (nb == 0 || nb == 1)
        return (0);
    if (nb == 2147483647)
        return (1);
    if (nb > 2147483647 || nb < 0)
        return (0);
    for (i = 2; i <= div; i ++) {
        if (nb % i == 0) {
            return (0);
            }
    }
    return (1);
}
