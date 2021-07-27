#include <iostream>
using namespace std;


string mostraDiaDaSemana (int k) {
  string dia;
  switch (k) {
    case 0: 
      dia = "Sabado";
      break;
    case 1: 
      dia = "Domingo";
      break;
    case 2: 
      dia = "Segunda-feira";
      break;
    case 3: 
      dia = "Terca-feira";
      break;
    case 4: 
      dia = "Quarta-feira";
      break;
    case 5: 
      dia = "Quinta-feira";
      break;
  default:
    dia = "Sexta-feira";
  }
  return dia;
}


bool ehAnoBissexto (int ano) {
  if ((ano % 400 == 0) || 
      ((ano % 4 == 0) && (ano % 100 != 0)))
    return true;
  return false;
}


bool validarData (int dia, int mes, int ano) {
  if (ano < 0)
    return false;
  else if (ano > 2021)
    return false;
  else if (mes <= 0 || mes > 12)
    return false;
  else if (mes == 1 || mes == 3 || mes == 5 ||
           mes == 7 || mes == 8 || mes == 10 ||
           mes == 12) {
          if (dia <= 0 || dia > 31)
            return false;
  } else if (mes == 4 || mes == 6 || 
            mes == 9 || mes == 11) {
          if (dia <= 0 || dia > 30)
            return false;
  } else if (mes == 2) {
      if (dia >= 29 && !ehAnoBissexto(ano))
        return false;
  }
  return true;
}

int main() {
  int k, dia, mes, ano; 
  bool dataValida = true;

  do{
     cout << "Digite o dia: " <<endl; cin >> dia;
     cout << "Digite o mes: " <<endl; cin >> mes; 
     cout << "Dgite o ano: " <<endl; cin >> ano;

  dataValida = validarData (dia, mes, ano);
   
  if (dataValida) {
    k = dia + 2 * mes + (3*(mes+1))/5 + ano + ano/4 - ano/100 + ano/400 + 2;
    k = k % 7;
    cout << mostraDiaDaSemana(k) << endl;
  }
  }while(dataValida==1);
  if(dataValida == 0){
    cout << "Data Invalida";
  }
  return 0;
}
