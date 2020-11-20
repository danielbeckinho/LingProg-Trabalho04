Trabalho 04 de de Linguagens de Programacao
Prof: Miguel Campista
Aluno: Daniel Becker Endres Mendonca
DRE: 112093743


            INTRODUCAO

    Este programa implementa atraves de templates uma arvore binaria para armazenar cadastros de pacientes de um hospital ficticio.
Ele eh capaz de detectar tentativas de recadastro de pacientes jah existentes e impedi-las alem de acusar que o paciente buscado nao 
foi encontrado, ambas implementadas por erros especializados derivados atraves de heranca da classe runtime_error.


            COMPILACAO E LINKEDICAO
    
    O processo de compilacao e linkedicao eh feito automaticamente pelo gnu make. Eh necessario que todos os arquivos referentes ao
programa estejam no mesmo diretorio para que a automacao possa reconhece-los. Certificando-se disso eh soh executar o comando make 
no diretorio onde estao os arquivos e fazer vista grossa para os avisos de compilacao referentes aa possivel chegada ao final de funcoes 
de tipo nao-void sem retornar valor algum. Executado o comando make, eh soh iniciar o programa usando ./mainProgram.


            INSTRUCOES DE USO 
    
    O programa se vale da interface em prompt de comando de modo que todas as funcoes estejam acessiveis digitando-se os numeros 
correspondentes. Nessa implementacao de cadastro os pacientes podem ter nomes que incluam espacos.