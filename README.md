<h1 align="center" >Algoritmo de Quine-McCluskey</h1> 

<div>
  <img src="https://github.com/GabrielaSchmitt/Quine-McCluskey/assets/86369677/c55f6d98-008c-45e0-a51f-b4ddc1347053" style="width: 400px; height: auto;" align="left" alt="Edward McCluskey tag" />

  <br></br>

  <h3 >
  Edward J. McCluskey é uma figura proeminente na história da ciência da computação, conhecido por suas contribuições fundamentais para o avanço do design de chips e da automação do processo de design. Graduado com honras em matemática e física pela Bowdoin College em Maine, ele prosseguiu seus estudos em engenharia elétrica no MIT, onde obteve seu doutorado em 1956. Durante seu período como pesquisador associado na Bell Telephone Laboratories, entre 1955 e 1959, McCluskey desempenhou um papel crucial no desenvolvimento do algoritmo Quine-McCluskey. Este algoritmo revolucionou a indústria de semicondutores ao permitir o design eficiente de chips complexos, pavimentando o caminho para o sucesso contínuo do setor. Seus feitos renderam-lhe reconhecimento significativo, incluindo o prêmio da Association for Computing Machinery (ACM) em 2008, em reconhecimento à sua notável contribuição para a área. Sua passagem pela Universidade de Stanford como professor emérito solidificou ainda mais sua reputação como líder e pioneiro na ciência da computação. O legado de Edward J. McCluskey continua a inspirar gerações futuras de cientistas da computação e engenheiros eletrônicos, e sua contribuição para o algoritmo de Quine-McCluskey permanece como um marco na história do design digital.
  </h3>
</div>

<br></br>
<h2 align="left" >Explicação do algoritmo 🤓</h2>
<p> Este repositório contém a implementação do algoritmo Quine-McCluskey em C++ para simplificar funções booleanas. O algoritmo é utilizado para reduzir a complexidade de uma função booleana, minimizando o número de termos na sua representação. Confira o flow chart abaixo da sequência de passos.  </p>

[![](https://mermaid.ink/img/pako:eNpdkN9PwjAQgP-Vpr5AMggdrGx70MjvGRQivqj1obAijaxdus44mv3vdgUT4kOT6313313OwJ1MGYzhp6L5ASyfibh_32iq9AfodG7ByCx5ocEjF5qprKiJGLn82MyVLHOwrcANkHuAGjR2aGLWimcMJFl-5DsqdHFn2cQy8MoKVzJtJSkTmu8rsE6K9oU-ybOaiKkLZv9F4IVuj8zKZo7PzbQoGg09Nppmyvx6yqJl1-YZP7H2hVwmzIhYuCAxrsL2j-U3U1aQuPxDa1XqvNRgs1rb3ofz0iKFHszsGShP7cUMEQAQqA8sYwTGNkyp-iKQiNrW0VLLTSV2MNaqZB4s85RqNuHUHjr7S-ZUvEl5_YWxgT8w7iDc79o3QBgNUBjggQcrGKMQdfvYH_p-iKMQ4wjXHjw5A-r6UYCjXtgL-n409ANc_wLYeJAj?type=png)](https://mermaid.live/edit#pako:eNpdkN9PwjAQgP-Vpr5AMggdrGx70MjvGRQivqj1obAijaxdus44mv3vdgUT4kOT6313313OwJ1MGYzhp6L5ASyfibh_32iq9AfodG7ByCx5ocEjF5qprKiJGLn82MyVLHOwrcANkHuAGjR2aGLWimcMJFl-5DsqdHFn2cQy8MoKVzJtJSkTmu8rsE6K9oU-ybOaiKkLZv9F4IVuj8zKZo7PzbQoGg09Nppmyvx6yqJl1-YZP7H2hVwmzIhYuCAxrsL2j-U3U1aQuPxDa1XqvNRgs1rb3ofz0iKFHszsGShP7cUMEQAQqA8sYwTGNkyp-iKQiNrW0VLLTSV2MNaqZB4s85RqNuHUHjr7S-ZUvEl5_YWxgT8w7iDc79o3QBgNUBjggQcrGKMQdfvYH_p-iKMQ4wjXHjw5A-r6UYCjXtgL-n409ANc_wLYeJAj)

<h2 align="left" >Funções 🧩</h2>

#### `converter`
* Converte um array de inteiros em um vetor de inteiros.
* Útil para manipulação de dados de entrada.

#### `generate_min_circuit`
* Cria registros para cada número da tabela verdade, armazenando sua representação binária e linhas da tabela verdade.
* Simplifica os primos implicantes iterativamente usando a função `primos_implicantes`.
* Remove redundâncias e linhas isoladas usando as funções `eliminar_redundancias` e `detectando_linhas_isoladas`.
* Encontra registros correspondentes aos resultados simplificados usando a função `achar_registros_correspondentes`.
* Exibe os resultados na tela usando a função `exibir_na_tela`.

#### `primos_implicantes`
* Simplifica os primos implicantes na lista de registros nBin.
* Combina registros que diferem em apenas um bit, reduzindo a complexidade da expressão booleana.
* Retorna true se alguma simplificação foi realizada, false caso contrário.

#### `detectando_linhas_isoladas`
* Identifica linhas isoladas na tabela verdade.
* Retorna uma lista contendo as linhas que possuem elementos únicos.
  
#### `eliminar_redundancias`
* Elimina linhas redundantes da tabela verdade.
* Garante que cada linha represente uma combinação única de valores de entrada.
  
#### `achar_registros_correspondentes`
* Encontra os registros na lista nBin que correspondem aos resultados da simplificação.
* Associa cada resultado da expressão booleana mínima aos registros originais.

#### `exibir_na_tela`
* Imprime a expressão booleana mínima na tela.
* Formata a expressão de forma legível para o usuário.

<h2 align="left" >Equipe 🧠</h2>

- Gabriela Cristina Schmitt (25733150)
- Felipe dos Santos Fabienski (8113112368)
- Luiz Henrique Vieira Steff (25878301)
- Vinícius Dionizio Patrocínio (27038386)
