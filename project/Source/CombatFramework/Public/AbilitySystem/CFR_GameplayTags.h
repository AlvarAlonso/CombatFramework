#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FCFR_GameplayTags
{
public:
    static const FCFR_GameplayTags& Get() { return GameplayTags; }
    static void InitializeNativeGameplayTags();

    /*** Combo ***/
    FGameplayTag Combo_CanCombo;
    FGameplayTag Combo_CanJumpToComboSection;
    FGameplayTag Combo_ContinueCombo;


    /*** Gameplay Abilities ***/
    // Tags related to GameplayAbilities. 

    FGameplayTag Ability_Fullbody;
    FGameplayTag Ability_Montage;
    FGameplayTag Ability_Melee;
    FGameplayTag Ability_Air;

    /* Ability Names */
    // Actual activatable abilities (via input, passives, etc...)
    FGameplayTag Ability_Dash;
    FGameplayTag Ability_Dodge;
    FGameplayTag Ability_Jump;
    FGameplayTag Ability_LightAttack;
    FGameplayTag Ability_HeavyAttack;
    FGameplayTag Ability_AirAttack;
    FGameplayTag Ability_LaunchAttack;
    FGameplayTag Ability_FallAttack;
    FGameplayTag Ability_LungeAttack;

    /* Hit Reacts*/

     // Combines with the rest of HitReact tags (for example, to create the logic of a HitReact_Back_Launch).
    FGameplayTag HitReact_Back;

    FGameplayTag HitReact_Basic;
    FGameplayTag HitReact_Knockback;
    FGameplayTag HitReact_Air;
    FGameplayTag HitReact_Launch;
    FGameplayTag HitReact_Death;


    /*** GameplayEffects ***/

    FGameplayTag GameplayEffect_Damage;
    FGameplayTag GameplayEffect_Launch;
    

    /*** Hitboxes ***/

    FGameplayTag Hitbox_Weapon_Front;
    FGameplayTag Hitbox_Weapon_Area;
    FGameplayTag Hitbox_Weapon_Fall;
    FGameplayTag Hitbox_Weapon_Lunge;
    FGameplayTag Hitbox_Weapon_WideFront;
    FGameplayTag Hitbox_Weapon_HeavyFront;
    FGameplayTag Hitbox_Barrier;


    /*** Gameplay Events ***/

    FGameplayTag GameplayEvent_Jumped;
    FGameplayTag GameplayEvent_DoubleJumped;
    FGameplayTag GameplayEvent_GoingToLand;

    /* Montage */
    FGameplayTag GameplayEvent_Montage;
    FGameplayTag GameplayEvent_Montage_Melee;
    FGameplayTag GameplayEvent_Montage_Melee_First;
    FGameplayTag GameplayEvent_Montage_Melee_Second;
    FGameplayTag GameplayEvent_Montage_Melee_Third;

    /*** Statuses ***/
    FGameplayTag Status_Dead;
    FGameplayTag Status_KnockedUp;
    FGameplayTag Status_OnAir;
    FGameplayTag Status_Attacking;
    FGameplayTag Status_AirStable;

private:
    static FCFR_GameplayTags GameplayTags;
};