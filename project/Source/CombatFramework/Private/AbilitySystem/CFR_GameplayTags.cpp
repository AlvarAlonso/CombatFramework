#include "AbilitySystem/CFR_GameplayTags.h"
#include "GameplayTagsManager.h"

FCFR_GameplayTags FCFR_GameplayTags::GameplayTags;

void FCFR_GameplayTags::InitializeNativeGameplayTags()
{
    /*** Combo ***/

    GameplayTags.Combo_CanCombo = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Combo.CanCombo"),
        FString("The actor is in a time interval when it can combo to next ability given the right input."));

    GameplayTags.Combo_CanJumpToComboSection = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Combo.CanJumpToComboSection"),
        FString("The character is in a time interval where it can jump to next combo section immediatly, given the right input.."));

    GameplayTags.Combo_ContinueCombo = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Combo.ContinueCombo"),
        FString("The actor received the correct input to continue with a combo."));
    
    
    /*** Gameplay Abilities ***/
    
    GameplayTags.Ability_Fullbody = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.Fullbody"),
        FString("An avatar actor should only have one fullbody ability active at the same time. It should not coexist with abilities that use part of the body."));

    GameplayTags.Ability_Montage = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.Montage"),
        FString(""));

    /* Ability Names */

    GameplayTags.Ability_Dash = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.Dash"),
        FString(""));

    GameplayTags.Ability_Dodge = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.Dodge"),
        FString(""));

    GameplayTags.Ability_Jump = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.Jump"),
        FString(""));

    GameplayTags.Ability_LightAttack = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.LightAttack"),
        FString(""));

    GameplayTags.Ability_HeavyAttack = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.HeavyAttack"),
        FString(""));

    GameplayTags.Ability_AirAttack = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.AirAttack"),
        FString(""));

    GameplayTags.Ability_LaunchAttack = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.LaunchAttack"),
        FString(""));

    GameplayTags.Ability_FallAttack = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.FallAttack"),
        FString(""));

    GameplayTags.Ability_LungeAttack = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.LungeAttack"),
        FString(""));

    /* Hit Reacts*/

    GameplayTags.HitReact_Back = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.HitReact.Back"), 
        FString("Combines with the rest of HitReact tags (for example, to create the logic of a HitReact_Back_Launch)."));
    
    GameplayTags.HitReact_Basic = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.HitReact.Basic"),
        FString(""));
    
    GameplayTags.HitReact_Knockback = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.HitReact.Knockback"),
        FString(""));
   
    GameplayTags.HitReact_Air = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.HitReact.Air"),
        FString(""));
    
    GameplayTags.HitReact_Death = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayAbility.HitReact.Death"),
        FString(""));


    /*** Gameplay Effects ***/

    GameplayTags.GameplayEffect_Launch = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayEffect.Launch"),
        FString(""));


    /*** Hitboxes ***/

    GameplayTags.Hitbox_Weapon_Front = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Hitbox.Weapon.Front"),
        FString(""));


    /*** Gameplay Events ***/

    GameplayTags.GameplayEvent_Jumped = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayEvent.Jumped"),
        FString(""));

    GameplayTags.GameplayEvent_DoubleJumped = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayEvent.DoubleJumped"),
        FString(""));

    GameplayTags.GameplayEvent_GoingToLand = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("GameplayEvent.GoingToLand"),
        FString(""));


    /*** Statuses ***/

    GameplayTags.Status_Dead = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Status.Dead"),
        FString(""));

    GameplayTags.Status_KnockedUp = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Status.KnockedUp"),
        FString(""));

    GameplayTags.Status_OnAir = UGameplayTagsManager::Get().AddNativeGameplayTag(
        FName("Status.OnAir"),
        FString(""));
}
