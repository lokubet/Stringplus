typedef long unsigned size_t;

size_t s21_strlen(const char *str)
{
    size_t len = 0;
    for(; str[len]; len++);
    return len + 1;
} 