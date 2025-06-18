#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define TOTALCHARACTERS 4
#define ORBTYPES 4
#define MAXORBS 10
#define EFFECTS 12

typedef enum 
{
    Lightning,
    Frost,
    Dark,
    Plasma
} OrbType;
typedef enum
{
    Ironclad,
    Silent,
    Defect,
    Watcher,
    Colorless
} CharacterLineUp;
typedef enum
{
    Attack,
    Skill,
    Power
} CardType;
typedef enum
{
    Self,
    Enemy,
    AllEnemies,
    Random
} TargetType;
typedef enum
{
    Damage,
    Block,
    Poison,
    Weak,
    Vulnerable,
    Frail,
    CardDraw,
    StrengthModify,
    DexModify,
    FocusModify,
    Intangible,
    ExhaustCard,
    ExhausSelf,
    KeepBlock,

} EffectType;
typedef enum
{
    Instant,
    StartOfTurn,
    EndOfTurn
} CombatEvent;
typedef struct
{
    int baseStrength;
    int evokeBonus;
} StandardOrb;
typedef struct 
{
    int baseStrength;
    int storedValue;
} DarkOrb;
typedef struct 
{
    OrbType type;
    union 
    {
        StandardOrb standard;
        DarkOrb dark;
    };
    
} OrbUnion;
typedef struct
{
    OrbUnion orbs[MAXORBS];
    int activeOrbs;
    int maxOrbs;
} OrbHalo;
typedef struct 
{
    int strength;
    int dexterity;
    int focus;
    int currentEnergy;
    int maximumEnergy;
    int health;
    int maxHealth;
} Stats;

typedef struct 
{
    CharacterLineUp hero;
    OrbHalo halo;
    Stats characterStats;
} Character;
typedef struct 
{
    CardType type;
    CharacterLineUp cardClass;
    union
    {
        PowerCard powerCard;
        DefaultCard defaultCard;
    };
} Card;
typedef struct 
{
    int manaCost;
    int effectAmount;
    Effect effects[EFFECTS];
} PowerCard;
typedef struct 
{
    int manaCost;
    TargetType target;
    int effectAmount;
    Effect effects[EFFECTS];
} DefaultCard;
typedef struct 
{
    EffectType effect;
    int effectStrength;
    int additionalTurns;
    CombatEvent effectEvent;
} Effect;


void printStats(Stats charStats);
void combatOptions(Character *pPlayerChar, OrbUnion orbPalette[]);
void renderOrbs(OrbHalo halo);
void channelOrb(OrbHalo *pCharHalo, OrbUnion orbPalette[]);
void evokeOrb(Character *pCurrentChar);
void pickCharacter(CharacterLineUp *pCurrentHero);

int main (void){
    CharacterLineUp pickedHero = Ironclad;
    Character currentHero;
    OrbUnion orbLineUp[ORBTYPES] = {
        {
            .type = Lightning, 
            .standard.baseStrength = 3,
            .standard.evokeBonus = 5 
        },
        {
            .type = Frost, 
            .standard.baseStrength = 2,
            .standard.evokeBonus = 4 
        },
        {
            .type = Dark, 
            .dark.baseStrength = 6,
            .dark.storedValue = 0
        },
        {
            .type = Plasma, 
            .standard.baseStrength = 1,
            .standard.evokeBonus = 1 
        },
    };

    Character charLineUp[TOTALCHARACTERS] = {
        {
            .hero = Ironclad,
            .halo.maxOrbs = 3,
            .characterStats.strength = 0,
            .characterStats.dexterity = 0,
            .characterStats.focus = 0,
            .characterStats.maximumEnergy = 3, 
            .characterStats.health = 80,
            .characterStats.maxHealth = 80
        }, 
        {
            .hero = Silent,
            .halo.maxOrbs = 3,
            .characterStats.strength = 0,
            .characterStats.dexterity = 0,
            .characterStats.focus = 0,
            .characterStats.maximumEnergy = 3, 
            .characterStats.health = 70,
            .characterStats.maxHealth = 70
        }, 
        {
            .hero = Defect,
            .halo.orbs[0] = orbLineUp[Lightning],
            .halo.activeOrbs = 1,
            .halo.maxOrbs = 3,
            .characterStats.strength = 0,
            .characterStats.dexterity = 0,
            .characterStats.focus = 0,
            .characterStats.maximumEnergy = 3, 
            .characterStats.health = 70,
            .characterStats.maxHealth = 70
        }, 
        {
            .hero = Watcher,
            .halo.maxOrbs = 3,
            .characterStats.strength = 0,
            .characterStats.dexterity = 0,
            .characterStats.focus = 0,
            .characterStats.maximumEnergy = 3, 
            .characterStats.health = 75,
            .characterStats.maxHealth = 75
        }, 
    };

    pickCharacter(&pickedHero);
    currentHero = charLineUp[pickedHero];

    //main loop
    for (int i = 0; i < 10; i++)
    {
        if (currentHero.halo.activeOrbs || currentHero.hero == Defect)
        {
            renderOrbs(currentHero.halo);
        }
        printStats(currentHero.characterStats);
        combatOptions(&currentHero, orbLineUp);
    }
    
        
}

void combatOptions(Character *pPlayerChar, OrbUnion orbPalette[]){
    int input = 0;
    printf("(1) Increase maxorb, (2) Channel Orb, (3)Evoke Orb (4) Increase Stats\n");
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        (*pPlayerChar).halo.maxOrbs++;
        break;
    case 2:
        if ((*pPlayerChar).halo.activeOrbs<(*pPlayerChar).halo.maxOrbs)
        {
            channelOrb(&(*pPlayerChar).halo, orbPalette);
        }
        else{
            evokeOrb(pPlayerChar);
            channelOrb(&(*pPlayerChar).halo, orbPalette);
        }
        break;
    case 3:
        evokeOrb(pPlayerChar);
        break;
    case 4:
        //handleStats();
        break;
    
    default:
        break;
    }
}

void printStats(Stats charStats){
    printf("HP %d/%d\n", charStats.health, charStats.maxHealth);
    if (charStats.strength)
    {
        printf("Strength: %d, ", charStats.strength);
    }
    if (charStats.dexterity)
    {
        printf("Dexterity: %d, ", charStats.dexterity);
    }
    if (charStats.focus)
    {
        printf("Focu: %d, ", charStats.focus-2);
    }
    printf("\n");
}
void channelOrb(OrbHalo *pCharHalo, OrbUnion orbPalette[]){
    int input = 0;
    printf("Channel (1)Lightning, (2)Frost, (3)Dark, (4)Plasma: ");
    scanf("%d", &input);
    input--;
    switch (input)
    {
    case Lightning:
        (*pCharHalo).orbs[(*pCharHalo).activeOrbs] = orbPalette[Lightning];
        (*pCharHalo).activeOrbs++;
        break;
    case Frost:
        (*pCharHalo).orbs[(*pCharHalo).activeOrbs] = orbPalette[Frost];
        (*pCharHalo).activeOrbs++;
        break;
    case Dark:
        (*pCharHalo).orbs[(*pCharHalo).activeOrbs] = orbPalette[Dark];
        (*pCharHalo).activeOrbs++;
        break;
    case Plasma:
        (*pCharHalo).orbs[(*pCharHalo).activeOrbs] = orbPalette[Plasma];
        (*pCharHalo).activeOrbs++;
        break;
    default:
        break;
    }
}

void renderOrbs(OrbHalo halo){
    for (int i = halo.maxOrbs-1; i >=0; i--)
    {
        if (i>=halo.activeOrbs)
        {
            printf("[ ] ");
        }
        else{
            printf("[");
            switch (halo.orbs[i].type)
            {
            case Lightning:
                printf("L");
                break;
            case Frost:
                printf("F");
                break;
            case Dark:
                printf("D");
                break;
            case Plasma:
                printf("P");
                break;
            
            default:
                break;
            }
            printf("] ");
        }
    }
    printf("\n");
    for (int i = 0; i < halo.activeOrbs; i++)
    {
        /* code */
    }
    
}

void evokeOrb(Character *pCurrentChar){
    
    if ((*pCurrentChar).halo.activeOrbs)
    {
        switch ((*pCurrentChar).halo.orbs[0].type)
        {
        case Lightning:
            printf("You deal %d damage\n", (*pCurrentChar).halo.orbs[0].standard.baseStrength+(*pCurrentChar).characterStats.focus+(*pCurrentChar).halo.orbs[0].standard.evokeBonus);
            break;
        case Frost:
            printf("You gain %d armor\n", (*pCurrentChar).halo.orbs[0].standard.baseStrength+(*pCurrentChar).characterStats.focus+(*pCurrentChar).halo.orbs[0].standard.evokeBonus);
            break;
        case Dark:
            printf("You deal %d damage\n", (*pCurrentChar).halo.orbs[0].dark.storedValue);
            break;
        case Plasma:
            printf("You gain %d energy\n", (*pCurrentChar).halo.orbs[0].standard.baseStrength+(*pCurrentChar).halo.orbs[0].standard.evokeBonus);
            (*pCurrentChar).characterStats.currentEnergy+=2;
            break;
        default:
            break;
        }
        for (int i = 0; i < (*pCurrentChar).halo.activeOrbs-1; i++)
        {
            (*pCurrentChar).halo.orbs[i] = (*pCurrentChar).halo.orbs[i+1];
        }
        (*pCurrentChar).halo.activeOrbs--;
        
    }
    else{
        printf("No active orbs!\n");
    }
    
    
}
void pickCharacter(CharacterLineUp *pCurrentHero){
    unsigned int input = 0;
    printf("Select character \n");
    printf("(1)Ironclad\n");
    printf("(2)Silent\n");
    printf("(3)Defect\n");
    printf("(4)Watcher\n:");

    scanf("%d", &input);
    if (input>4)
    {
        input=4;
    }
    
    (*pCurrentHero) = input-1;

}