#include <stdio.h>
# Super Trunfo - Cidades (Todos os Níveis)
def cadastrar_carta():
    print("\nCadastro de nova carta:")
    carta = {
        "estado": input("Estado: "),
        "codigo": input("Código da carta: "),
        "nome": input("Nome da cidade: "),
        "populacao": int(input("População: ")),
        "area": float(input("Área (km²): ")),
        "pib": float(input("PIB (R$ bilhões): ")),
        "pontos_turisticos": int(input("Número de pontos turísticos: "))
    }
    carta["densidade"] = carta["populacao"] / carta["area"]
    return carta

def exibir_carta(carta):
    print(f"\nCarta: {carta['nome']} ({carta['estado']})")
    print(f"Código: {carta['codigo']}")
    print(f"População: {carta['populacao']}")
    print(f"Área: {carta['area']} km²")
    print(f"PIB: R$ {carta['pib']} bilhões")
    print(f"Pontos Turísticos: {carta['pontos_turisticos']}")
    print(f"Densidade Populacional: {carta['densidade']:.2f} hab/km²")

def comparar_um_atributo(c1, c2, atributo):
    if atributo == "densidade":
        return c1 if c1[atributo] < c2[atributo] else c2 if c1[atributo] > c2[atributo] else None
    else:
        return c1 if c1[atributo] > c2[atributo] else c2 if c1[atributo] < c2[atributo] else None

def comparar_dois_atributos(c1, c2, a1, a2):
    resultado1 = comparar_um_atributo(c1, c2, a1)
    if resultado1 is None:
        resultado2 = comparar_um_atributo(c1, c2, a2)
        return resultado2
    return resultado1

def menu_comparacao(c1, c2):
    while True:
        print("\n🧠 Menu de Comparação")
        print("1. Comparar por 1 atributo")
        print("2. Comparar por 2 atributos")
        print("3. Comparação completa (todos)")
        print("0. Sair")
        opcao = input("Escolha a opção: ")

        match opcao:
            case "1":
                atributo = input("Escolha o atributo (populacao, area, pib, pontos_turisticos, densidade): ").lower()
                if atributo not in c1:
                    print("Atributo inválido.")
                else:
                    vencedor = comparar_um_atributo(c1, c2, atributo)
                    print("\n🏁 Resultado:")
                    if vencedor is None:
                        print("Empate!")
                    else:
                        print(f"A carta vencedora foi: {vencedor['nome']} (comparando {atributo})")
            case "2":
                a1 = input("Primeiro atributo: ").lower()
                a2 = input("Segundo atributo: ").lower()
                if a1 not in c1 or a2 not in c1:
                    print("Atributos inválidos.")
                else:
                    vencedor = comparar_dois_atributos(c1, c2, a1, a2)
                    print("\n🏁 Resultado:")
                    if vencedor is None:
                        print("Empate!")
                    else:
                        print(f"A carta vencedora foi: {vencedor['nome']} (comparando {a1} e {a2})")
            case "3":
                atributos = ["populacao", "area", "pib", "pontos_turisticos", "densidade"]
                pontos_c1 = 0
                pontos_c2 = 0
                for atributo in atributos:
                    vencedor = comparar_um_atributo(c1, c2, atributo)
                    if vencedor == c1:
                        pontos_c1 += 1
                    elif vencedor == c2:
                        pontos_c2 += 1
                print("\n🔍 Comparação Final:")
                print(f"{c1['nome']}: {pontos_c1} ponto(s)")
                print(f"{c2['nome']}: {pontos_c2} ponto(s)")
                if pontos_c1 == pontos_c2:
                    print("Empate geral!")
                else:
                    vencedor = c1 if pontos_c1 > pontos_c2 else c2
                    print(f"A carta vencedora foi: {vencedor['nome']} (comparação geral)")
            case "0":
                print("Saindo...")
                break
            case _:
                print("Opção inválida!")

# Programa Principal
print("🌍 Super Trunfo - Cidades 🏙️")
print("Cadastro da primeira carta:")
carta1 = cadastrar_carta()
print("Cadastro da segunda carta:")
carta2 = cadastrar_carta()

print("\n🃏 Cartas cadastradas:")
exibir_carta(carta1)
exibir_carta(carta2)

menu_comparacao(carta1, carta2)


    return 0;
}
