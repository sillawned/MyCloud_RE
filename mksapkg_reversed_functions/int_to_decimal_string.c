
/* // digit_table: Table contenant l'alphabet personnalisé, mais seuls les chiffres '0'-'9' sont
   utilisés pour l'encodage décimal.
   
   // Conversion de l'entier en chaîne de caractères, chiffre par chiffre, en utilisant
   digit_table.
   // La chaîne est construite à l'envers (du moins significatif au plus significatif).
   
   // Si la valeur est négative, ajoute le signe '-'.
   
   // Inverse la chaîne pour obtenir le bon ordre.
   
   // Retourne un pointeur vers la chaîne encodée. */

undefined1 * int_to_decimal_string(int value)

{
  char *pcVar2;
  char *out_ptr;
  char *cur_ptr;
  char *swap_ptr;
  int tmp_value;
  char digit_table [88];
  char tmp_char;
  
  builtin_strncpy(digit_table + 0x40,"tuvwxyz",8);
  builtin_strncpy(digit_table,"zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrs",
                  0x40);
  out_ptr = stringified_integer;
  do {
    tmp_value = value;
    cur_ptr = out_ptr;
    out_ptr = cur_ptr + 1;
    *cur_ptr = digit_table[tmp_value % 10 + 0x23];
    value = tmp_value / 10;
  } while (tmp_value / 10 != 0);
  pcVar2 = out_ptr;
  if (tmp_value < 0) {
    pcVar2 = cur_ptr + 2;
    *out_ptr = '-';
    cur_ptr = out_ptr;
  }
  *pcVar2 = '\0';
  out_ptr = stringified_integer;
  if (stringified_integer < cur_ptr) {
    do {
      tmp_char = *cur_ptr;
      swap_ptr = cur_ptr + -1;
      pcVar2 = out_ptr + 1;
      *cur_ptr = *out_ptr;
      *out_ptr = tmp_char;
      out_ptr = pcVar2;
      cur_ptr = swap_ptr;
    } while (pcVar2 < swap_ptr);
  }
  return stringified_integer;
}

