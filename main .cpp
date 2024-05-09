#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <algorithm>

class Numeros {
public:
    std::vector<int> linhas_tab_verdade; // Armazena as linhas da tabela verdade
    std::string representacao_binaria;   // Representação binária dos números
};

class Registro {
public:
    Numeros nums;   // Números associados ao registro
    bool utilizado; // Flag para indicar se o registro foi utilizado
};

// Função para comparar o tamanho de dois vetores
bool comparar_tamanho(const std::vector<int>& a, const std::vector<int>& b) {
    return a.size() > b.size(); // Ordena do maior para o menor
}

// Função para remover elementos de um vetor com base em outro vetor
bool consome_vetor(std::vector<int> linha, std::vector<int>& numeros_originais) {
    bool utilizou = false;
    for(int num : linha){
        auto it = std::find(numeros_originais.begin(), numeros_originais.end(), num);
        // Verificar se o número foi encontrado
        if (it != numeros_originais.end()) {
            utilizou = true;
            numeros_originais.erase(it);
        }
    }
    return utilizou;
}

// Função para eliminar redundâncias nas linhas da tabela verdade
std::vector<std::vector<int>> eliminar_redundancias(std::vector<std::vector<int>>& linhas_resultado, std::vector<std::vector<int>>& linhas_isoladas, std::vector<int>& nums_originais_tab_vdd){
    std::sort(linhas_resultado.begin(), linhas_resultado.end(), comparar_tamanho);

    std::vector<std::vector<int>> resposta_final;
    
    for (std::vector<int> linha : linhas_isoladas){
        if(consome_vetor(linha, nums_originais_tab_vdd)){
            resposta_final.push_back(linha);
        }
    }
    for (std::vector<int> linha : linhas_resultado){
        if(consome_vetor(linha, nums_originais_tab_vdd)){
            resposta_final.push_back(linha);
        }
    }    
    return resposta_final;
}

// Função para encontrar registros correspondentes aos resultados
std::vector<Registro> achar_registros_correspondentes(std::vector<Registro> lista_registros ,std::vector<std::vector<int>> lista_resultados){
    std::vector<Registro> resultados;
    for (Registro reg : lista_registros){
        for (std::vector<int> resultado : lista_resultados){
           if (std::equal(resultado.begin(), resultado.end(), reg.nums.linhas_tab_verdade.begin())){
                resultados.push_back(reg);
           } 
        }
    }
    return resultados;
}

// Função para detectar linhas isoladas na tabela verdade
std::vector<std::vector<int>> detectando_linhas_isoladas(std::vector<std::vector<int>> linhas_originais_tab_verdade) {
    std::vector<std::vector<int>> isolados;

    for (std::vector<int>& linhas_tab_vdd : linhas_originais_tab_verdade) {
        bool possui_elemento_unico = false;
        for (int nums : linhas_tab_vdd) {
            bool elemento_unico = true;
            for (std::vector<int>& outra_lista : linhas_originais_tab_verdade) {
                if (linhas_tab_vdd != outra_lista) { 
                    if (std::find(outra_lista.begin(), outra_lista.end(), nums) != outra_lista.end()) {
                        elemento_unico = false;
                    }
                }
            }            
            if (elemento_unico) {
                possui_elemento_unico = true;
            } 
        }
        if (possui_elemento_unico) {
            isolados.push_back(linhas_tab_vdd);
        }
    }
    return isolados;
}

// Função para exibir na tela os resultados
void exibir_na_tela(std::vector<Registro> registros){
    
    std::vector<std::string> entradas = {"H","G","F","E","D","C","B","A"};
    std::vector<std::string> retorno;
    for(Registro reg : registros){
        for (int i = 0; i < 8; i++)
        {
            if (reg.nums.representacao_binaria[i] == '0'){
                retorno.push_back("~");
                retorno.push_back(entradas[i] + " ");
            }else if (reg.nums.representacao_binaria[i] == '1'){
                retorno.push_back(entradas[i] + " ");
            };
        }
        retorno.push_back(" + ");        
    }      
    auto it = retorno.begin() + retorno.size();

    for (std::string letra : retorno){
        std::cout << letra;
    }
}

// Função para encontrar os primos implicantes
bool primos_implicantes(std::vector<Registro>& nBin){
    std::vector<Registro> pares;  // Vetor para armazenar os pares de primos implicantes
    bool simplificou = false; // Flag para indicar se houve simplificação durante a execução
    // Iteração sobre cada registro na lista de registros
    for (Registro& registro : nBin){       
        Numeros num = registro.nums; // Obtém o número associado ao registro
        // Iteração sobre cada registro vizinho na lista de registros
        for (Registro& registro_vizinho : nBin){
            Numeros num_vizinho = registro_vizinho.nums; // Obtém o número associado ao registro vizinho
            int diferencas = 0; // Variável para contar as diferenças entre os números binários
            // Verifica se o número binário do registro atual é menor que o do registro vizinho
            if (num.representacao_binaria < num_vizinho.representacao_binaria){
                std::string identificacao = ""; // String para identificar a diferença entre os números binários
                // Iteração sobre cada bit nos números binários
                for (int i = 0; i < 8 ; i++ ) {
                    if(num.representacao_binaria[i] == num_vizinho.representacao_binaria[i]){
                        identificacao += num.representacao_binaria[i]; // Se os bits são iguais, adiciona o bit ao identificador
                    }else{
                        diferencas+= 1; // Se os bits são diferentes, marca a diferença com "-"
                        identificacao += "-";
                    }
                }                
                // Se houver apenas uma diferença, adiciona o par de primos implicantes
                if (diferencas == 1){
                    simplificou = true;
                    registro.utilizado = true; // Marca os registros como utilizados para evitar duplicatas
                    registro_vizinho.utilizado = true;
                    Numeros num_salvo;
                    num_salvo.linhas_tab_verdade.insert(num_salvo.linhas_tab_verdade.end(), num.linhas_tab_verdade.begin(), num.linhas_tab_verdade.end());
                    num_salvo.linhas_tab_verdade.insert(num_salvo.linhas_tab_verdade.end(), num_vizinho.linhas_tab_verdade.begin(), num_vizinho.linhas_tab_verdade.end());
                    num_salvo.representacao_binaria = identificacao; 
                    Registro registro_inserido;
                    registro_inserido.nums = num_salvo; // Cria um novo registro com o número combinado
                    registro_inserido.utilizado = false;
                    pares.push_back(registro_inserido);
                }
            }
        }               
    }
    // Ordena e combina os pares com os registros não utilizados
    std::vector<Registro> pares_ordenado;      
    for (Registro registro : nBin){
        if(registro.utilizado == false) {
            pares_ordenado.push_back(registro);
        }
    }    
    pares_ordenado.insert(pares_ordenado.end(), pares.begin(), pares.end());  
    nBin.clear();
    nBin.assign(pares_ordenado.begin(), pares_ordenado.end());  

    return simplificou; // Retorna verdadeiro se houve simplificação, falso caso contrário
}
std::vector<int> converter(int v[], size_t size) {
    std::vector<int> result;
    for(int i = 0; i < size; i++){
		result.push_back(v[i]);
	}
   
    return result;
}


void generate_min_circuit(int entradas[], int n){     
    std::vector<Registro> nBin;
    
    std::vector<int> nReais = converter(entradas, n);

    // Criando registros para os números da tabela verdade
    for (int num : nReais) {
        Numeros num_inserido;
        num_inserido.linhas_tab_verdade.push_back(num);
        num_inserido.representacao_binaria = std::bitset<8>(num).to_string();

        Registro registro_inserido;
        registro_inserido.nums = num_inserido;
        registro_inserido.utilizado = false;
        nBin.push_back(registro_inserido);
    }
    
    // Simplificando os primos implicantes
    bool simplificando;
    do {
        simplificando = primos_implicantes(nBin);
    } while (simplificando);    
    
    // Removendo redundâncias e linhas isoladas
    std::vector<Registro> reduzido;

    for (int i = 0 ; i < (nBin.size() - 1) ; i ++) {
        if(nBin[i].nums.representacao_binaria != nBin[i + 1].nums.representacao_binaria){
            reduzido.push_back(nBin[i]);
        } else if (i == nBin.size() - 2){
            reduzido.push_back(nBin[i]);
        }        
    }    

    std::vector<std::vector<int>> linhas;
    
    for (Registro reg :reduzido){
        linhas.push_back(reg.nums.linhas_tab_verdade);
    }
    
    // Detectando linhas isoladas na tabela verdade
    std::vector<std::vector<int>> linhas_contendo_nums_isolados = detectando_linhas_isoladas(linhas);        

    // Eliminando redundâncias
    std::vector<std::vector<int>> linhas_resultantes = eliminar_redundancias(linhas,linhas_contendo_nums_isolados,nReais);    

    // Encontrando registros correspondentes aos resultados
    std::vector<Registro> registros_resultantes = achar_registros_correspondentes(nBin,linhas_resultantes);

    // Exibindo os resultados na tela
    exibir_na_tela(registros_resultantes);

    
}

int main()
{

	int v[] = {4, 8, 9, 10, 11, 12, 14, 15};

	generate_min_circuit(v, 8);
	return 0;
}


