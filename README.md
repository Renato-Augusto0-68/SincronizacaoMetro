# SincronizacaoMetro

projeto da cadeira de Infraestrutura de Software (SO), do professor Marcelo Arcoverde

#### Para rodar o projeto, utilize o comando:
        make run
#### isso fará a ativação do comando e a execução do processo
#### Para limpar o output, pós execução rode o comando:
        make clean
#### Implementado em Windows (através de WSL)
## Arquivos usados:

- sync-car-runner.c (teste para verificar compatibilidade)

- sync_car.c (funções implementadas atraves de POSIX, via pthreads, apenas utilizando de mutex e cond, pelas funções prototipadas em sync_car.h)

- sync_car.h (Declarações dos protótipos das funções utilizadas e da struct station utilizada em sync_car.c)