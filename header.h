#ifdef __cplusplus
extern "C"{
#endif
#ifndef RLC_HEADER
#ifdef RLC_C_HEADER
#undef RLC_C_HEADER
#define RLC_HEADER

#include "stddef.h"
#include "stdint.h"
#define RLC_GET_FUNCTION_DECLS
#define RLC_GET_TYPE_DECLS
#endif
#endif
#ifdef RLC_GET_TYPE_DECLS
typedef union BIntT0T14T BIntT0T14T;
typedef union VectorTBIntT0T14TT VectorTBIntT0T14TT;
typedef union Deck Deck;
typedef union HiddenTDeckT HiddenTDeckT;
typedef union BoundedVectorTBIntT0T14TT20T BoundedVectorTBIntT0T14TT20T;
typedef union HiddenTBoundedVectorTBIntT0T14TT20TT HiddenTBoundedVectorTBIntT0T14TT20TT;
typedef union VectorTboolT VectorTboolT;
typedef union VectorTint8_tT VectorTint8_tT;
typedef union String String;
typedef union VectorTStringT VectorTStringT;
typedef union VectorTdoubleT VectorTdoubleT;
typedef union BIntT0T52T BIntT0T52T;
typedef union GameShuffleSource GameShuffleSource;
typedef union GameShuffleTarget GameShuffleTarget;
typedef union GameHit GameHit;
typedef union GameStand GameStand;
typedef union Shuffle Shuffle;
typedef union Game Game;
struct AnyGameAction;
#undef RLC_GET_TYPE_DECLS
#endif

#ifdef RLC_TYPE
RLC_TYPE(BInt)
RLC_TYPE(Vector)
RLC_TYPE(Deck)
RLC_TYPE(Hidden)
RLC_TYPE(BoundedVector)
RLC_TYPE(Hidden)
RLC_TYPE(Vector)
RLC_TYPE(Vector)
RLC_TYPE(String)
RLC_TYPE(Vector)
RLC_TYPE(Vector)
RLC_TYPE(BInt)
RLC_TYPE(GameShuffleSource)
RLC_TYPE(GameShuffleTarget)
RLC_TYPE(GameHit)
RLC_TYPE(GameStand)
RLC_TYPE(Shuffle)
RLC_TYPE(Game)
#undef RLC_TYPE
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__Game(union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(init, rl_m_init__Game, Game_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__Game_r_bool(bool * __result, union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__Game_r_bool, can_Game_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__Shuffle(union Shuffle * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Shuffle * self
RLC_VISIT_FUNCTION(init, rl_m_init__Shuffle, Shuffle_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__Shuffle_r_bool(bool * __result, union Shuffle * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Shuffle * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__Shuffle_r_bool, can_Shuffle_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__AnyGameAction(struct AnyGameAction * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS struct AnyGameAction * self
RLC_VISIT_FUNCTION(init, rl_m_init__AnyGameAction, init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__AnyGameAction_r_bool(bool * __result, struct AnyGameAction * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS struct AnyGameAction * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__AnyGameAction_r_bool, can_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__HiddenTBoundedVectorTBIntT0T14TT20TT(union HiddenTBoundedVectorTBIntT0T14TT20TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTBoundedVectorTBIntT0T14TT20TT * self
RLC_VISIT_FUNCTION(init, rl_m_init__HiddenTBoundedVectorTBIntT0T14TT20TT, Hidden_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__HiddenTBoundedVectorTBIntT0T14TT20TT_r_bool(bool * __result, union HiddenTBoundedVectorTBIntT0T14TT20TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTBoundedVectorTBIntT0T14TT20TT * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__HiddenTBoundedVectorTBIntT0T14TT20TT_r_bool, can_Hidden_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__BoundedVectorTBIntT0T14TT20T(union BoundedVectorTBIntT0T14TT20T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self
RLC_VISIT_FUNCTION(init, rl_m_init__BoundedVectorTBIntT0T14TT20T, BoundedVector_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__BoundedVectorTBIntT0T14TT20T_r_bool, can_BoundedVector_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__HiddenTDeckT(union HiddenTDeckT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTDeckT * self
RLC_VISIT_FUNCTION(init, rl_m_init__HiddenTDeckT, Hidden_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__HiddenTDeckT_r_bool(bool * __result, union HiddenTDeckT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTDeckT * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__HiddenTDeckT_r_bool, can_Hidden_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__strlit(char* * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * self
RLC_VISIT_FUNCTION(init, rl_m_init__strlit, init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__strlit_r_bool(bool * __result, char* * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__strlit_r_bool, can_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__int8_t_1(int8_t * self[1]);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t *[1] self
RLC_VISIT_FUNCTION(init, rl_m_init__int8_t_1, init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__int8_t_1_r_bool(bool * __result, int8_t * self[1]);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t *[1] self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__int8_t_1_r_bool, can_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__int8_t_8(int8_t * self[8]);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t *[8] self
RLC_VISIT_FUNCTION(init, rl_m_init__int8_t_8, init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__int8_t_8_r_bool(bool * __result, int8_t * self[8]);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t *[8] self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__int8_t_8_r_bool, can_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__GameStand(union GameStand * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameStand * self
RLC_VISIT_FUNCTION(init, rl_m_init__GameStand, GameStand_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__GameStand_r_bool(bool * __result, union GameStand * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameStand * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__GameStand_r_bool, can_GameStand_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__GameHit(union GameHit * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameHit * self
RLC_VISIT_FUNCTION(init, rl_m_init__GameHit, GameHit_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__GameHit_r_bool(bool * __result, union GameHit * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameHit * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__GameHit_r_bool, can_GameHit_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__GameShuffleTarget(union GameShuffleTarget * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleTarget * self
RLC_VISIT_FUNCTION(init, rl_m_init__GameShuffleTarget, GameShuffleTarget_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__GameShuffleTarget_r_bool(bool * __result, union GameShuffleTarget * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleTarget * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__GameShuffleTarget_r_bool, can_GameShuffleTarget_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__GameShuffleSource(union GameShuffleSource * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleSource * self
RLC_VISIT_FUNCTION(init, rl_m_init__GameShuffleSource, GameShuffleSource_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__GameShuffleSource_r_bool(bool * __result, union GameShuffleSource * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleSource * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__GameShuffleSource_r_bool, can_GameShuffleSource_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__Game_Game(union Game * self, union Game * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * self, union Game * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__Game_Game, Game_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__Game_Game_r_bool(bool * __result, union Game * self, union Game * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * self, union Game * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__Game_Game_r_bool, can_Game_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__Shuffle_Shuffle(union Shuffle * self, union Shuffle * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Shuffle * self, union Shuffle * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__Shuffle_Shuffle, Shuffle_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__Shuffle_Shuffle_r_bool(bool * __result, union Shuffle * self, union Shuffle * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Shuffle * self, union Shuffle * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__Shuffle_Shuffle_r_bool, can_Shuffle_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__HiddenTBoundedVectorTBIntT0T14TT20TT_HiddenTBoundedVectorTBIntT0T14TT20TT(union HiddenTBoundedVectorTBIntT0T14TT20TT * self, union HiddenTBoundedVectorTBIntT0T14TT20TT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union HiddenTBoundedVectorTBIntT0T14TT20TT * self, union HiddenTBoundedVectorTBIntT0T14TT20TT * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__HiddenTBoundedVectorTBIntT0T14TT20TT_HiddenTBoundedVectorTBIntT0T14TT20TT, Hidden_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__HiddenTBoundedVectorTBIntT0T14TT20TT_HiddenTBoundedVectorTBIntT0T14TT20TT_r_bool(bool * __result, union HiddenTBoundedVectorTBIntT0T14TT20TT * self, union HiddenTBoundedVectorTBIntT0T14TT20TT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union HiddenTBoundedVectorTBIntT0T14TT20TT * self, union HiddenTBoundedVectorTBIntT0T14TT20TT * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__HiddenTBoundedVectorTBIntT0T14TT20TT_HiddenTBoundedVectorTBIntT0T14TT20TT_r_bool, can_Hidden_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__HiddenTDeckT_HiddenTDeckT(union HiddenTDeckT * self, union HiddenTDeckT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union HiddenTDeckT * self, union HiddenTDeckT * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__HiddenTDeckT_HiddenTDeckT, Hidden_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__HiddenTDeckT_HiddenTDeckT_r_bool(bool * __result, union HiddenTDeckT * self, union HiddenTDeckT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union HiddenTDeckT * self, union HiddenTDeckT * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__HiddenTDeckT_HiddenTDeckT_r_bool, can_Hidden_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__Deck_Deck(union Deck * self, union Deck * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * self, union Deck * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__Deck_Deck, Deck_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__Deck_Deck_r_bool(bool * __result, union Deck * self, union Deck * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * self, union Deck * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__Deck_Deck_r_bool, can_Deck_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__AnyGameAction_GameShuffleSource(struct AnyGameAction * self, union GameShuffleSource * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameShuffleSource * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__AnyGameAction_GameShuffleSource, assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__AnyGameAction_GameShuffleSource_r_bool(bool * __result, struct AnyGameAction * self, union GameShuffleSource * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameShuffleSource * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__AnyGameAction_GameShuffleSource_r_bool, can_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__AnyGameAction_GameShuffleTarget(struct AnyGameAction * self, union GameShuffleTarget * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameShuffleTarget * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__AnyGameAction_GameShuffleTarget, assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__AnyGameAction_GameShuffleTarget_r_bool(bool * __result, struct AnyGameAction * self, union GameShuffleTarget * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameShuffleTarget * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__AnyGameAction_GameShuffleTarget_r_bool, can_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__AnyGameAction_GameHit(struct AnyGameAction * self, union GameHit * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameHit * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__AnyGameAction_GameHit, assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__AnyGameAction_GameHit_r_bool(bool * __result, struct AnyGameAction * self, union GameHit * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameHit * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__AnyGameAction_GameHit_r_bool, can_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__AnyGameAction_GameStand(struct AnyGameAction * self, union GameStand * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameStand * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__AnyGameAction_GameStand, assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__AnyGameAction_GameStand_r_bool(bool * __result, struct AnyGameAction * self, union GameStand * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union GameStand * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__AnyGameAction_GameStand_r_bool, can_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__AnyGameAction_AnyGameAction(struct AnyGameAction * self, struct AnyGameAction * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, struct AnyGameAction * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__AnyGameAction_AnyGameAction, assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__AnyGameAction_AnyGameAction_r_bool(bool * __result, struct AnyGameAction * self, struct AnyGameAction * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, struct AnyGameAction * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__AnyGameAction_AnyGameAction_r_bool, can_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__GameStand_GameStand(union GameStand * self, union GameStand * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameStand * self, union GameStand * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__GameStand_GameStand, GameStand_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__GameStand_GameStand_r_bool(bool * __result, union GameStand * self, union GameStand * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameStand * self, union GameStand * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__GameStand_GameStand_r_bool, can_GameStand_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__GameHit_GameHit(union GameHit * self, union GameHit * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameHit * self, union GameHit * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__GameHit_GameHit, GameHit_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__GameHit_GameHit_r_bool(bool * __result, union GameHit * self, union GameHit * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameHit * self, union GameHit * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__GameHit_GameHit_r_bool, can_GameHit_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__GameShuffleTarget_GameShuffleTarget(union GameShuffleTarget * self, union GameShuffleTarget * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleTarget * self, union GameShuffleTarget * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__GameShuffleTarget_GameShuffleTarget, GameShuffleTarget_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__GameShuffleTarget_GameShuffleTarget_r_bool(bool * __result, union GameShuffleTarget * self, union GameShuffleTarget * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleTarget * self, union GameShuffleTarget * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__GameShuffleTarget_GameShuffleTarget_r_bool, can_GameShuffleTarget_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__GameShuffleSource_GameShuffleSource(union GameShuffleSource * self, union GameShuffleSource * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleSource * self, union GameShuffleSource * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__GameShuffleSource_GameShuffleSource, GameShuffleSource_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__GameShuffleSource_GameShuffleSource_r_bool(bool * __result, union GameShuffleSource * self, union GameShuffleSource * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleSource * self, union GameShuffleSource * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__GameShuffleSource_GameShuffleSource_r_bool, can_GameShuffleSource_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__BIntT0T52T_BIntT0T52T(union BIntT0T52T * self, union BIntT0T52T * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T52T * self, union BIntT0T52T * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__BIntT0T52T_BIntT0T52T, BInt_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__BIntT0T52T_BIntT0T52T_r_bool(bool * __result, union BIntT0T52T * self, union BIntT0T52T * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T52T * self, union BIntT0T52T * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__BIntT0T52T_BIntT0T52T_r_bool, can_BInt_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__BIntT0T14T_BIntT0T14T(union BIntT0T14T * self, union BIntT0T14T * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * self, union BIntT0T14T * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__BIntT0T14T_BIntT0T14T, BInt_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__BIntT0T14T_BIntT0T14T_r_bool(bool * __result, union BIntT0T14T * self, union BIntT0T14T * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * self, union BIntT0T14T * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__BIntT0T14T_BIntT0T14T_r_bool, can_BInt_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__strlit_strlit(char* * self, char* * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS char* * self, char* * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__strlit_strlit, assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__strlit_strlit_r_bool(bool * __result, char* * self, char* * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS char* * self, char* * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__strlit_strlit_r_bool, can_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__String_String(union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__String_String, String_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__String_String_r_bool(bool * __result, union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__String_String_r_bool, can_String_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__String(union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__String, String_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__String_r_bool(bool * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__String_r_bool, can_String_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__Deck(union Deck * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Deck * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__Deck, Deck_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__Deck_r_bool(bool * __result, union Deck * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Deck * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__Deck_r_bool, can_Deck_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__Game(union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__Game, Game_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__Game_r_bool(bool * __result, union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__Game_r_bool, can_Game_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__HiddenTDeckT(union HiddenTDeckT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTDeckT * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__HiddenTDeckT, Hidden_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__HiddenTDeckT_r_bool(bool * __result, union HiddenTDeckT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTDeckT * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__HiddenTDeckT_r_bool, can_Hidden_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__BoundedVectorTBIntT0T14TT20T(union BoundedVectorTBIntT0T14TT20T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__BoundedVectorTBIntT0T14TT20T, BoundedVector_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__BoundedVectorTBIntT0T14TT20T_r_bool, can_BoundedVector_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__HiddenTBoundedVectorTBIntT0T14TT20TT(union HiddenTBoundedVectorTBIntT0T14TT20TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTBoundedVectorTBIntT0T14TT20TT * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__HiddenTBoundedVectorTBIntT0T14TT20TT, Hidden_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__HiddenTBoundedVectorTBIntT0T14TT20TT_r_bool(bool * __result, union HiddenTBoundedVectorTBIntT0T14TT20TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTBoundedVectorTBIntT0T14TT20TT * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__HiddenTBoundedVectorTBIntT0T14TT20TT_r_bool, can_Hidden_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__HiddenTDeckT_String(union HiddenTDeckT * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union HiddenTDeckT * to_add, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__HiddenTDeckT_String, Hidden_append_to_string, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__HiddenTDeckT_String_r_bool(bool * __result, union HiddenTDeckT * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union HiddenTDeckT * to_add, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__HiddenTDeckT_String_r_bool, can_Hidden_append_to_string, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_print_string__String(union String * s);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * s
RLC_VISIT_FUNCTION(print_string, rl_print_string__String, String_print_string, void ,  s)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_print_string__String_r_bool(bool * __result, union String * s);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * s
RLC_VISIT_FUNCTION(can_print_string, rl_can_print_string__String_r_bool, can_String_print_string, bool ,  s)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_print_string_lit__strlit(char* * s);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * s
RLC_VISIT_FUNCTION(print_string_lit, rl_print_string_lit__strlit, print_string_lit, void ,  s)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_print_string_lit__strlit_r_bool(bool * __result, char* * s);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * s
RLC_VISIT_FUNCTION(can_print_string_lit, rl_can_print_string_lit__strlit_r_bool, can_print_string_lit, bool ,  s)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_print__String(union String * to_print);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * to_print
RLC_VISIT_FUNCTION(print, rl_print__String, String_print, void ,  to_print)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_print__String_r_bool(bool * __result, union String * to_print);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * to_print
RLC_VISIT_FUNCTION(can_print, rl_can_print__String_r_bool, can_String_print, bool ,  to_print)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_vector__int64_t_VectorTint8_tT(int64_t * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(append_to_vector, rl_append_to_vector__int64_t_VectorTint8_tT, append_to_vector, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_vector__int64_t_VectorTint8_tT_r_bool(bool * __result, int64_t * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(can_append_to_vector, rl_can_append_to_vector__int64_t_VectorTint8_tT_r_bool, can_append_to_vector, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_vector__double_VectorTint8_tT(double * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS double * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(append_to_vector, rl_append_to_vector__double_VectorTint8_tT, append_to_vector, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_vector__double_VectorTint8_tT_r_bool(bool * __result, double * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS double * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(can_append_to_vector, rl_can_append_to_vector__double_VectorTint8_tT_r_bool, can_append_to_vector, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_vector__bool_VectorTint8_tT(bool * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(append_to_vector, rl_append_to_vector__bool_VectorTint8_tT, append_to_vector, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_vector__bool_VectorTint8_tT_r_bool(bool * __result, bool * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(can_append_to_vector, rl_can_append_to_vector__bool_VectorTint8_tT_r_bool, can_append_to_vector, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_vector__int8_t_VectorTint8_tT(int8_t * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int8_t * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(append_to_vector, rl_append_to_vector__int8_t_VectorTint8_tT, append_to_vector, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_vector__int8_t_VectorTint8_tT_r_bool(bool * __result, int8_t * to_add, union VectorTint8_tT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int8_t * to_add, union VectorTint8_tT * output
RLC_VISIT_FUNCTION(can_append_to_vector, rl_can_append_to_vector__int8_t_VectorTint8_tT_r_bool, can_append_to_vector, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_from_vector__int64_t_VectorTint8_tT_int64_t_r_bool(bool * __result, int64_t * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(parse_from_vector, rl_parse_from_vector__int64_t_VectorTint8_tT_int64_t_r_bool, parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_from_vector__int64_t_VectorTint8_tT_int64_t_r_bool(bool * __result, int64_t * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(can_parse_from_vector, rl_can_parse_from_vector__int64_t_VectorTint8_tT_int64_t_r_bool, can_parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_from_vector__double_VectorTint8_tT_int64_t_r_bool(bool * __result, double * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(parse_from_vector, rl_parse_from_vector__double_VectorTint8_tT_int64_t_r_bool, parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_from_vector__double_VectorTint8_tT_int64_t_r_bool(bool * __result, double * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(can_parse_from_vector, rl_can_parse_from_vector__double_VectorTint8_tT_int64_t_r_bool, can_parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_from_vector__bool_VectorTint8_tT_int64_t_r_bool(bool * __result, bool * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS bool * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(parse_from_vector, rl_parse_from_vector__bool_VectorTint8_tT_int64_t_r_bool, parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_from_vector__bool_VectorTint8_tT_int64_t_r_bool(bool * __result, bool * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS bool * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(can_parse_from_vector, rl_can_parse_from_vector__bool_VectorTint8_tT_int64_t_r_bool, can_parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_from_vector__int8_t_VectorTint8_tT_int64_t_r_bool(bool * __result, int8_t * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int8_t * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(parse_from_vector, rl_parse_from_vector__int8_t_VectorTint8_tT_int64_t_r_bool, parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_from_vector__int8_t_VectorTint8_tT_int64_t_r_bool(bool * __result, int8_t * result, union VectorTint8_tT * input, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int8_t * result, union VectorTint8_tT * input, int64_t * index
RLC_VISIT_FUNCTION(can_parse_from_vector, rl_can_parse_from_vector__int8_t_VectorTint8_tT_int64_t_r_bool, can_parse_from_vector, bool ,  result,  input,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_from_byte_vector__int8_t_VectorTint8_tT_int64_t_r_bool(bool * __result, int8_t * result, union VectorTint8_tT * input, int64_t * read_bytes);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int8_t * result, union VectorTint8_tT * input, int64_t * read_bytes
RLC_VISIT_FUNCTION(from_byte_vector, rl_from_byte_vector__int8_t_VectorTint8_tT_int64_t_r_bool, from_byte_vector, bool ,  result,  input,  read_bytes)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_from_byte_vector__int8_t_VectorTint8_tT_int64_t_r_bool(bool * __result, int8_t * result, union VectorTint8_tT * input, int64_t * read_bytes);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int8_t * result, union VectorTint8_tT * input, int64_t * read_bytes
RLC_VISIT_FUNCTION(can_from_byte_vector, rl_can_from_byte_vector__int8_t_VectorTint8_tT_int64_t_r_bool, can_from_byte_vector, bool ,  result,  input,  read_bytes)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__VectorTBIntT0T14TT(union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(init, rl_m_init__VectorTBIntT0T14TT, Vector_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__VectorTBIntT0T14TT_r_bool(bool * __result, union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__VectorTBIntT0T14TT_r_bool, can_Vector_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__VectorTint8_tT(union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(init, rl_m_init__VectorTint8_tT, Vector_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__VectorTint8_tT_r_bool(bool * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__VectorTint8_tT_r_bool, can_Vector_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__VectorTdoubleT(union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(init, rl_m_init__VectorTdoubleT, Vector_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__VectorTdoubleT_r_bool(bool * __result, union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__VectorTdoubleT_r_bool, can_Vector_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__VectorTStringT(union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(init, rl_m_init__VectorTStringT, Vector_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__VectorTStringT_r_bool(bool * __result, union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__VectorTStringT_r_bool, can_Vector_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__VectorTboolT(union VectorTboolT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTboolT * self
RLC_VISIT_FUNCTION(init, rl_m_init__VectorTboolT, Vector_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__VectorTboolT_r_bool(bool * __result, union VectorTboolT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTboolT * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__VectorTboolT_r_bool, can_Vector_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__VectorTint8_tT(union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__VectorTint8_tT, Vector_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__VectorTint8_tT_r_bool(bool * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__VectorTint8_tT_r_bool, can_Vector_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__VectorTBIntT0T14TT(union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__VectorTBIntT0T14TT, Vector_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__VectorTBIntT0T14TT_r_bool(bool * __result, union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__VectorTBIntT0T14TT_r_bool, can_Vector_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__VectorTdoubleT(union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__VectorTdoubleT, Vector_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__VectorTdoubleT_r_bool(bool * __result, union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__VectorTdoubleT_r_bool, can_Vector_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__VectorTStringT(union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__VectorTStringT, Vector_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__VectorTStringT_r_bool(bool * __result, union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__VectorTStringT_r_bool, can_Vector_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop__VectorTboolT(union VectorTboolT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTboolT * self
RLC_VISIT_FUNCTION(drop, rl_m_drop__VectorTboolT, Vector_drop, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop__VectorTboolT_r_bool(bool * __result, union VectorTboolT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTboolT * self
RLC_VISIT_FUNCTION(can_drop, rl_m_can_drop__VectorTboolT_r_bool, can_Vector_drop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__VectorTBIntT0T14TT_VectorTBIntT0T14TT(union VectorTBIntT0T14TT * self, union VectorTBIntT0T14TT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, union VectorTBIntT0T14TT * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__VectorTBIntT0T14TT_VectorTBIntT0T14TT, Vector_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__VectorTBIntT0T14TT_VectorTBIntT0T14TT_r_bool(bool * __result, union VectorTBIntT0T14TT * self, union VectorTBIntT0T14TT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, union VectorTBIntT0T14TT * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__VectorTBIntT0T14TT_VectorTBIntT0T14TT_r_bool, can_Vector_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__VectorTint8_tT_VectorTint8_tT(union VectorTint8_tT * self, union VectorTint8_tT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, union VectorTint8_tT * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__VectorTint8_tT_VectorTint8_tT, Vector_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__VectorTint8_tT_VectorTint8_tT_r_bool(bool * __result, union VectorTint8_tT * self, union VectorTint8_tT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, union VectorTint8_tT * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__VectorTint8_tT_VectorTint8_tT_r_bool, can_Vector_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__VectorTdoubleT_VectorTdoubleT(union VectorTdoubleT * self, union VectorTdoubleT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, union VectorTdoubleT * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__VectorTdoubleT_VectorTdoubleT, Vector_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__VectorTdoubleT_VectorTdoubleT_r_bool(bool * __result, union VectorTdoubleT * self, union VectorTdoubleT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, union VectorTdoubleT * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__VectorTdoubleT_VectorTdoubleT_r_bool, can_Vector_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__VectorTStringT_VectorTStringT(union VectorTStringT * self, union VectorTStringT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTStringT * self, union VectorTStringT * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__VectorTStringT_VectorTStringT, Vector_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__VectorTStringT_VectorTStringT_r_bool(bool * __result, union VectorTStringT * self, union VectorTStringT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTStringT * self, union VectorTStringT * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__VectorTStringT_VectorTStringT_r_bool, can_Vector_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__VectorTboolT_VectorTboolT(union VectorTboolT * self, union VectorTboolT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTboolT * self, union VectorTboolT * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__VectorTboolT_VectorTboolT, Vector_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__VectorTboolT_VectorTboolT_r_bool(bool * __result, union VectorTboolT * self, union VectorTboolT * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTboolT * self, union VectorTboolT * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__VectorTboolT_VectorTboolT_r_bool, can_Vector_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_resize__VectorTdoubleT_int64_t(union VectorTdoubleT * self, int64_t * new_size);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, int64_t * new_size
RLC_VISIT_FUNCTION(resize, rl_m_resize__VectorTdoubleT_int64_t, Vector_resize, void ,  self,  new_size)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_resize__VectorTdoubleT_int64_t_r_bool(bool * __result, union VectorTdoubleT * self, int64_t * new_size);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, int64_t * new_size
RLC_VISIT_FUNCTION(can_resize, rl_m_can_resize__VectorTdoubleT_int64_t_r_bool, can_Vector_resize, bool ,  self,  new_size)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_back__VectorTint8_tT_r_int8_tRef(int8_t* * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(back, rl_m_back__VectorTint8_tT_r_int8_tRef, Vector_back, int8_t* ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_back__VectorTint8_tT_r_bool(bool * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(can_back, rl_m_can_back__VectorTint8_tT_r_bool, can_Vector_back, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_get__VectorTint8_tT_int64_t_r_int8_tRef(int8_t* * __result, union VectorTint8_tT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, int64_t * index
RLC_VISIT_FUNCTION(get, rl_m_get__VectorTint8_tT_int64_t_r_int8_tRef, Vector_get, int8_t* ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_get__VectorTint8_tT_int64_t_r_bool(bool * __result, union VectorTint8_tT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, int64_t * index
RLC_VISIT_FUNCTION(can_get, rl_m_can_get__VectorTint8_tT_int64_t_r_bool, can_Vector_get, bool ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_get__VectorTdoubleT_int64_t_r_doubleRef(double* * __result, union VectorTdoubleT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, int64_t * index
RLC_VISIT_FUNCTION(get, rl_m_get__VectorTdoubleT_int64_t_r_doubleRef, Vector_get, double* ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_get__VectorTdoubleT_int64_t_r_bool(bool * __result, union VectorTdoubleT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, int64_t * index
RLC_VISIT_FUNCTION(can_get, rl_m_can_get__VectorTdoubleT_int64_t_r_bool, can_Vector_get, bool ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_get__VectorTStringT_int64_t_r_StringRef(union String* * __result, union VectorTStringT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTStringT * self, int64_t * index
RLC_VISIT_FUNCTION(get, rl_m_get__VectorTStringT_int64_t_r_StringRef, Vector_get, union String* ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_get__VectorTStringT_int64_t_r_bool(bool * __result, union VectorTStringT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTStringT * self, int64_t * index
RLC_VISIT_FUNCTION(can_get, rl_m_can_get__VectorTStringT_int64_t_r_bool, can_Vector_get, bool ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_get__VectorTBIntT0T14TT_int64_t_r_BIntT0T14TRef(union BIntT0T14T* * __result, union VectorTBIntT0T14TT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, int64_t * index
RLC_VISIT_FUNCTION(get, rl_m_get__VectorTBIntT0T14TT_int64_t_r_BIntT0T14TRef, Vector_get, union BIntT0T14T* ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_get__VectorTBIntT0T14TT_int64_t_r_bool(bool * __result, union VectorTBIntT0T14TT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, int64_t * index
RLC_VISIT_FUNCTION(can_get, rl_m_can_get__VectorTBIntT0T14TT_int64_t_r_bool, can_Vector_get, bool ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_get__VectorTboolT_int64_t_r_boolRef(bool* * __result, union VectorTboolT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTboolT * self, int64_t * index
RLC_VISIT_FUNCTION(get, rl_m_get__VectorTboolT_int64_t_r_boolRef, Vector_get, bool* ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_get__VectorTboolT_int64_t_r_bool(bool * __result, union VectorTboolT * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTboolT * self, int64_t * index
RLC_VISIT_FUNCTION(can_get, rl_m_can_get__VectorTboolT_int64_t_r_bool, can_Vector_get, bool ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_set__VectorTBIntT0T14TT_int64_t_BIntT0T14T(union VectorTBIntT0T14TT * self, int64_t * index, union BIntT0T14T * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, int64_t * index, union BIntT0T14T * value
RLC_VISIT_FUNCTION(set, rl_m_set__VectorTBIntT0T14TT_int64_t_BIntT0T14T, Vector_set, void ,  self,  index,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_set__VectorTBIntT0T14TT_int64_t_BIntT0T14T_r_bool(bool * __result, union VectorTBIntT0T14TT * self, int64_t * index, union BIntT0T14T * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, int64_t * index, union BIntT0T14T * value
RLC_VISIT_FUNCTION(can_set, rl_m_can_set__VectorTBIntT0T14TT_int64_t_BIntT0T14T_r_bool, can_Vector_set, bool ,  self,  index,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__VectorTint8_tT_int8_t(union VectorTint8_tT * self, int8_t * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, int8_t * value
RLC_VISIT_FUNCTION(append, rl_m_append__VectorTint8_tT_int8_t, Vector_append, void ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__VectorTint8_tT_int8_t_r_bool(bool * __result, union VectorTint8_tT * self, int8_t * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, int8_t * value
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__VectorTint8_tT_int8_t_r_bool, can_Vector_append, bool ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__VectorTboolT_bool(union VectorTboolT * self, bool * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTboolT * self, bool * value
RLC_VISIT_FUNCTION(append, rl_m_append__VectorTboolT_bool, Vector_append, void ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__VectorTboolT_bool_r_bool(bool * __result, union VectorTboolT * self, bool * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTboolT * self, bool * value
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__VectorTboolT_bool_r_bool, can_Vector_append, bool ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__VectorTStringT_String(union VectorTStringT * self, union String * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTStringT * self, union String * value
RLC_VISIT_FUNCTION(append, rl_m_append__VectorTStringT_String, Vector_append, void ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__VectorTStringT_String_r_bool(bool * __result, union VectorTStringT * self, union String * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTStringT * self, union String * value
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__VectorTStringT_String_r_bool, can_Vector_append, bool ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__VectorTdoubleT_double(union VectorTdoubleT * self, double * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, double * value
RLC_VISIT_FUNCTION(append, rl_m_append__VectorTdoubleT_double, Vector_append, void ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__VectorTdoubleT_double_r_bool(bool * __result, union VectorTdoubleT * self, double * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTdoubleT * self, double * value
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__VectorTdoubleT_double_r_bool, can_Vector_append, bool ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__VectorTBIntT0T14TT_BIntT0T14T(union VectorTBIntT0T14TT * self, union BIntT0T14T * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, union BIntT0T14T * value
RLC_VISIT_FUNCTION(append, rl_m_append__VectorTBIntT0T14TT_BIntT0T14T, Vector_append, void ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__VectorTBIntT0T14TT_BIntT0T14T_r_bool(bool * __result, union VectorTBIntT0T14TT * self, union BIntT0T14T * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self, union BIntT0T14T * value
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__VectorTBIntT0T14TT_BIntT0T14T_r_bool, can_Vector_append, bool ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_pop__VectorTint8_tT_r_int8_t(int8_t * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(pop, rl_m_pop__VectorTint8_tT_r_int8_t, Vector_pop, int8_t ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_pop__VectorTint8_tT_r_bool(bool * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(can_pop, rl_m_can_pop__VectorTint8_tT_r_bool, can_Vector_pop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_pop__VectorTStringT_r_String(union String * __result, union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(pop, rl_m_pop__VectorTStringT_r_String, Vector_pop, union String ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_pop__VectorTStringT_r_bool(bool * __result, union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(can_pop, rl_m_can_pop__VectorTStringT_r_bool, can_Vector_pop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_pop__VectorTBIntT0T14TT_r_BIntT0T14T(union BIntT0T14T * __result, union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(pop, rl_m_pop__VectorTBIntT0T14TT_r_BIntT0T14T, Vector_pop, union BIntT0T14T ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_pop__VectorTBIntT0T14TT_r_bool(bool * __result, union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(can_pop, rl_m_can_pop__VectorTBIntT0T14TT_r_bool, can_Vector_pop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_pop__VectorTdoubleT_r_double(double * __result, union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(pop, rl_m_pop__VectorTdoubleT_r_double, Vector_pop, double ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_pop__VectorTdoubleT_r_bool(bool * __result, union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(can_pop, rl_m_can_pop__VectorTdoubleT_r_bool, can_Vector_pop, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop_back__VectorTint8_tT_int64_t(union VectorTint8_tT * self, int64_t * quantity);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, int64_t * quantity
RLC_VISIT_FUNCTION(drop_back, rl_m_drop_back__VectorTint8_tT_int64_t, Vector_drop_back, void ,  self,  quantity)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop_back__VectorTint8_tT_int64_t_r_bool(bool * __result, union VectorTint8_tT * self, int64_t * quantity);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTint8_tT * self, int64_t * quantity
RLC_VISIT_FUNCTION(can_drop_back, rl_m_can_drop_back__VectorTint8_tT_int64_t_r_bool, can_Vector_drop_back, bool ,  self,  quantity)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_size__VectorTint8_tT_r_int64_t(int64_t * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(size, rl_m_size__VectorTint8_tT_r_int64_t, Vector_size, int64_t ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_size__VectorTint8_tT_r_bool(bool * __result, union VectorTint8_tT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTint8_tT * self
RLC_VISIT_FUNCTION(can_size, rl_m_can_size__VectorTint8_tT_r_bool, can_Vector_size, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_size__VectorTdoubleT_r_int64_t(int64_t * __result, union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(size, rl_m_size__VectorTdoubleT_r_int64_t, Vector_size, int64_t ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_size__VectorTdoubleT_r_bool(bool * __result, union VectorTdoubleT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTdoubleT * self
RLC_VISIT_FUNCTION(can_size, rl_m_can_size__VectorTdoubleT_r_bool, can_Vector_size, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_size__VectorTStringT_r_int64_t(int64_t * __result, union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(size, rl_m_size__VectorTStringT_r_int64_t, Vector_size, int64_t ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_size__VectorTStringT_r_bool(bool * __result, union VectorTStringT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTStringT * self
RLC_VISIT_FUNCTION(can_size, rl_m_can_size__VectorTStringT_r_bool, can_Vector_size, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_size__VectorTBIntT0T14TT_r_int64_t(int64_t * __result, union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(size, rl_m_size__VectorTBIntT0T14TT_r_int64_t, Vector_size, int64_t ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_size__VectorTBIntT0T14TT_r_bool(bool * __result, union VectorTBIntT0T14TT * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * self
RLC_VISIT_FUNCTION(can_size, rl_m_can_size__VectorTBIntT0T14TT_r_bool, can_Vector_size, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_assign__BoundedVectorTBIntT0T14TT20T_BoundedVectorTBIntT0T14TT20T(union BoundedVectorTBIntT0T14TT20T * self, union BoundedVectorTBIntT0T14TT20T * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self, union BoundedVectorTBIntT0T14TT20T * other
RLC_VISIT_FUNCTION(assign, rl_m_assign__BoundedVectorTBIntT0T14TT20T_BoundedVectorTBIntT0T14TT20T, BoundedVector_assign, void ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_assign__BoundedVectorTBIntT0T14TT20T_BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * self, union BoundedVectorTBIntT0T14TT20T * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self, union BoundedVectorTBIntT0T14TT20T * other
RLC_VISIT_FUNCTION(can_assign, rl_m_can_assign__BoundedVectorTBIntT0T14TT20T_BoundedVectorTBIntT0T14TT20T_r_bool, can_BoundedVector_assign, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_get__BoundedVectorTBIntT0T14TT20T_int64_t_r_BIntT0T14TRef(union BIntT0T14T* * __result, union BoundedVectorTBIntT0T14TT20T * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self, int64_t * index
RLC_VISIT_FUNCTION(get, rl_m_get__BoundedVectorTBIntT0T14TT20T_int64_t_r_BIntT0T14TRef, BoundedVector_get, union BIntT0T14T* ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_get__BoundedVectorTBIntT0T14TT20T_int64_t_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self, int64_t * index
RLC_VISIT_FUNCTION(can_get, rl_m_can_get__BoundedVectorTBIntT0T14TT20T_int64_t_r_bool, can_BoundedVector_get, bool ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__BoundedVectorTBIntT0T14TT20T_BIntT0T14T(union BoundedVectorTBIntT0T14TT20T * self, union BIntT0T14T * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self, union BIntT0T14T * value
RLC_VISIT_FUNCTION(append, rl_m_append__BoundedVectorTBIntT0T14TT20T_BIntT0T14T, BoundedVector_append, void ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__BoundedVectorTBIntT0T14TT20T_BIntT0T14T_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * self, union BIntT0T14T * value);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self, union BIntT0T14T * value
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__BoundedVectorTBIntT0T14TT20T_BIntT0T14T_r_bool, can_BoundedVector_append, bool ,  self,  value)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_size__BoundedVectorTBIntT0T14TT20T_r_int64_t(int64_t * __result, union BoundedVectorTBIntT0T14TT20T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self
RLC_VISIT_FUNCTION(size, rl_m_size__BoundedVectorTBIntT0T14TT20T_r_int64_t, BoundedVector_size, int64_t ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_size__BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * self
RLC_VISIT_FUNCTION(can_size, rl_m_can_size__BoundedVectorTBIntT0T14TT20T_r_bool, can_BoundedVector_size, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__String(union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(init, rl_m_init__String, String_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__String_r_bool(bool * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__String_r_bool, can_String_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__String_int8_t(union String * self, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int8_t * b
RLC_VISIT_FUNCTION(append, rl_m_append__String_int8_t, String_append, void ,  self,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__String_int8_t_r_bool(bool * __result, union String * self, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int8_t * b
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__String_int8_t_r_bool, can_String_append, bool ,  self,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_get__String_int64_t_r_int8_tRef(int8_t* * __result, union String * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int64_t * index
RLC_VISIT_FUNCTION(get, rl_m_get__String_int64_t_r_int8_tRef, String_get, int8_t* ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_get__String_int64_t_r_bool(bool * __result, union String * self, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int64_t * index
RLC_VISIT_FUNCTION(can_get, rl_m_can_get__String_int64_t_r_bool, can_String_get, bool ,  self,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_substring_matches__String_strlit_int64_t_r_bool(bool * __result, union String * self, char* * lit, int64_t * pos);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union String * self, char* * lit, int64_t * pos
RLC_VISIT_FUNCTION(substring_matches, rl_m_substring_matches__String_strlit_int64_t_r_bool, String_substring_matches, bool ,  self,  lit,  pos)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_substring_matches__String_strlit_int64_t_r_bool(bool * __result, union String * self, char* * lit, int64_t * pos);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union String * self, char* * lit, int64_t * pos
RLC_VISIT_FUNCTION(can_substring_matches, rl_m_can_substring_matches__String_strlit_int64_t_r_bool, can_String_substring_matches, bool ,  self,  lit,  pos)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_size__String_r_int64_t(int64_t * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(size, rl_m_size__String_r_int64_t, String_size, int64_t ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_size__String_r_bool(bool * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(can_size, rl_m_can_size__String_r_bool, can_String_size, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_count__String_int8_t_r_int64_t(int64_t * __result, union String * self, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int8_t * b
RLC_VISIT_FUNCTION(count, rl_m_count__String_int8_t_r_int64_t, String_count, int64_t ,  self,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_count__String_int8_t_r_bool(bool * __result, union String * self, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int8_t * b
RLC_VISIT_FUNCTION(can_count, rl_m_can_count__String_int8_t_r_bool, can_String_count, bool ,  self,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__String_strlit(union String * self, char* * str);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, char* * str
RLC_VISIT_FUNCTION(append, rl_m_append__String_strlit, String_append, void ,  self,  str)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__String_strlit_r_bool(bool * __result, union String * self, char* * str);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, char* * str
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__String_strlit_r_bool, can_String_append, bool ,  self,  str)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append__String_String(union String * self, union String * str);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * str
RLC_VISIT_FUNCTION(append, rl_m_append__String_String, String_append, void ,  self,  str)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append__String_String_r_bool(bool * __result, union String * self, union String * str);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * str
RLC_VISIT_FUNCTION(can_append, rl_m_can_append__String_String_r_bool, can_String_append, bool ,  self,  str)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_append_quoted__String_String(union String * self, union String * str);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * str
RLC_VISIT_FUNCTION(append_quoted, rl_m_append_quoted__String_String, String_append_quoted, void ,  self,  str)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_append_quoted__String_String_r_bool(bool * __result, union String * self, union String * str);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * str
RLC_VISIT_FUNCTION(can_append_quoted, rl_m_can_append_quoted__String_String_r_bool, can_String_append_quoted, bool ,  self,  str)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_add__String_String_r_String(union String * __result, union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(add, rl_m_add__String_String_r_String, String_add, union String ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_add__String_String_r_bool(bool * __result, union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(can_add, rl_m_can_add__String_String_r_bool, can_String_add, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_equal__String_strlit_r_bool(bool * __result, union String * self, char* * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, char* * other
RLC_VISIT_FUNCTION(equal, rl_m_equal__String_strlit_r_bool, String_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_equal__String_strlit_r_bool(bool * __result, union String * self, char* * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, char* * other
RLC_VISIT_FUNCTION(can_equal, rl_m_can_equal__String_strlit_r_bool, can_String_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_equal__String_String_r_bool(bool * __result, union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(equal, rl_m_equal__String_String_r_bool, String_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_equal__String_String_r_bool(bool * __result, union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(can_equal, rl_m_can_equal__String_String_r_bool, can_String_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_not_equal__String_String_r_bool(bool * __result, union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(not_equal, rl_m_not_equal__String_String_r_bool, String_not_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_not_equal__String_String_r_bool(bool * __result, union String * self, union String * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, union String * other
RLC_VISIT_FUNCTION(can_not_equal, rl_m_can_not_equal__String_String_r_bool, can_String_not_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_not_equal__String_strlit_r_bool(bool * __result, union String * self, char* * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, char* * other
RLC_VISIT_FUNCTION(not_equal, rl_m_not_equal__String_strlit_r_bool, String_not_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_not_equal__String_strlit_r_bool(bool * __result, union String * self, char* * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, char* * other
RLC_VISIT_FUNCTION(can_not_equal, rl_m_can_not_equal__String_strlit_r_bool, can_String_not_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_drop_back__String_int64_t(union String * self, int64_t * quantity);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int64_t * quantity
RLC_VISIT_FUNCTION(drop_back, rl_m_drop_back__String_int64_t, String_drop_back, void ,  self,  quantity)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_drop_back__String_int64_t_r_bool(bool * __result, union String * self, int64_t * quantity);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * self, int64_t * quantity
RLC_VISIT_FUNCTION(can_drop_back, rl_m_can_drop_back__String_int64_t_r_bool, can_String_drop_back, bool ,  self,  quantity)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_back__String_r_int8_tRef(int8_t* * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(back, rl_m_back__String_r_int8_tRef, String_back, int8_t* ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_back__String_r_bool(bool * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(can_back, rl_m_can_back__String_r_bool, can_String_back, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_reverse__String(union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(reverse, rl_m_reverse__String, String_reverse, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_reverse__String_r_bool(bool * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(can_reverse, rl_m_can_reverse__String_r_bool, can_String_reverse, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_to_indented_lines__String_r_String(union String * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(to_indented_lines, rl_m_to_indented_lines__String_r_String, String_to_indented_lines, union String ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_to_indented_lines__String_r_bool(bool * __result, union String * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union String * self
RLC_VISIT_FUNCTION(can_to_indented_lines, rl_m_can_to_indented_lines__String_r_bool, can_String_to_indented_lines, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_s__strlit_r_String(union String * __result, char* * literal);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * literal
RLC_VISIT_FUNCTION(s, rl_s__strlit_r_String, s, union String ,  literal)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_s__strlit_r_bool(bool * __result, char* * literal);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * literal
RLC_VISIT_FUNCTION(can_s, rl_can_s__strlit_r_bool, can_s, bool ,  literal)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__strlit_String(char* * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS char* * x, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__strlit_String, append_to_string, void ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__strlit_String_r_bool(bool * __result, char* * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS char* * x, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__strlit_String_r_bool, can_append_to_string, bool ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_load_file__String_String_r_bool(bool * __result, union String * file_name, union String * out);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * file_name, union String * out
RLC_VISIT_FUNCTION(load_file, rl_load_file__String_String_r_bool, String_load_file, bool ,  file_name,  out)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_load_file__String_String_r_bool(bool * __result, union String * file_name, union String * out);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * file_name, union String * out
RLC_VISIT_FUNCTION(can_load_file, rl_can_load_file__String_String_r_bool, can_String_load_file, bool ,  file_name,  out)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__int64_t_String(int64_t * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * x, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__int64_t_String, append_to_string, void ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__int64_t_String_r_bool(bool * __result, int64_t * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * x, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__int64_t_String_r_bool, can_append_to_string, bool ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__int8_t_String(int8_t * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int8_t * x, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__int8_t_String, append_to_string, void ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__int8_t_String_r_bool(bool * __result, int8_t * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int8_t * x, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__int8_t_String_r_bool, can_append_to_string, bool ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__double_String(double * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS double * x, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__double_String, append_to_string, void ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__double_String_r_bool(bool * __result, double * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS double * x, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__double_String_r_bool, can_append_to_string, bool ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__String_String(union String * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * x, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__String_String, String_append_to_string, void ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__String_String_r_bool(bool * __result, union String * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * x, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__String_String_r_bool, can_String_append_to_string, bool ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__bool_String(bool * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * x, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__bool_String, append_to_string, void ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__bool_String_r_bool(bool * __result, bool * x, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * x, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__bool_String_r_bool, can_append_to_string, bool ,  x,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__VectorTBIntT0T14TT_String(union VectorTBIntT0T14TT * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * to_add, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__VectorTBIntT0T14TT_String, Vector_append_to_string, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__VectorTBIntT0T14TT_String_r_bool(bool * __result, union VectorTBIntT0T14TT * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union VectorTBIntT0T14TT * to_add, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__VectorTBIntT0T14TT_String_r_bool, can_Vector_append_to_string, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__BoundedVectorTBIntT0T14TT20T_String(union BoundedVectorTBIntT0T14TT20T * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * to_add, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__BoundedVectorTBIntT0T14TT20T_String, BoundedVector_append_to_string, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__BoundedVectorTBIntT0T14TT20T_String_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * to_add, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__BoundedVectorTBIntT0T14TT20T_String_r_bool, can_BoundedVector_append_to_string, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_to_string__Deck_String(union Deck * to_stringyfi, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * to_stringyfi, union String * output
RLC_VISIT_FUNCTION(to_string, rl_to_string__Deck_String, Deck_to_string, void ,  to_stringyfi,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_to_string__Deck_String_r_bool(bool * __result, union Deck * to_stringyfi, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * to_stringyfi, union String * output
RLC_VISIT_FUNCTION(can_to_string, rl_can_to_string__Deck_String_r_bool, can_Deck_to_string, bool ,  to_stringyfi,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_to_string__HiddenTDeckT_r_String(union String * __result, union HiddenTDeckT * to_stringyfi);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTDeckT * to_stringyfi
RLC_VISIT_FUNCTION(to_string, rl_to_string__HiddenTDeckT_r_String, Hidden_to_string, union String ,  to_stringyfi)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_to_string__HiddenTDeckT_r_bool(bool * __result, union HiddenTDeckT * to_stringyfi);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union HiddenTDeckT * to_stringyfi
RLC_VISIT_FUNCTION(can_to_string, rl_can_to_string__HiddenTDeckT_r_bool, can_Hidden_to_string, bool ,  to_stringyfi)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_to_string__BoundedVectorTBIntT0T14TT20T_r_String(union String * __result, union BoundedVectorTBIntT0T14TT20T * to_stringyfi);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * to_stringyfi
RLC_VISIT_FUNCTION(to_string, rl_to_string__BoundedVectorTBIntT0T14TT20T_r_String, BoundedVector_to_string, union String ,  to_stringyfi)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_to_string__BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * to_stringyfi);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * to_stringyfi
RLC_VISIT_FUNCTION(can_to_string, rl_can_to_string__BoundedVectorTBIntT0T14TT20T_r_bool, can_BoundedVector_to_string, bool ,  to_stringyfi)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_is_space__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(is_space, rl_is_space__int8_t_r_bool, is_space, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_is_space__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(can_is_space, rl_can_is_space__int8_t_r_bool, can_is_space, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_is_alphanumeric__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(is_alphanumeric, rl_is_alphanumeric__int8_t_r_bool, is_alphanumeric, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_is_alphanumeric__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(can_is_alphanumeric, rl_can_is_alphanumeric__int8_t_r_bool, can_is_alphanumeric, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_is_open_paren__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(is_open_paren, rl_is_open_paren__int8_t_r_bool, is_open_paren, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_is_open_paren__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(can_is_open_paren, rl_can_is_open_paren__int8_t_r_bool, can_is_open_paren, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_is_close_paren__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(is_close_paren, rl_is_close_paren__int8_t_r_bool, is_close_paren, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_is_close_paren__int8_t_r_bool(bool * __result, int8_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * b
RLC_VISIT_FUNCTION(can_is_close_paren, rl_can_is_close_paren__int8_t_r_bool, can_is_close_paren, bool ,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_string__int64_t_String_int64_t_r_bool(bool * __result, int64_t * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(parse_string, rl_parse_string__int64_t_String_int64_t_r_bool, parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_string__int64_t_String_int64_t_r_bool(bool * __result, int64_t * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(can_parse_string, rl_can_parse_string__int64_t_String_int64_t_r_bool, can_parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_string__int8_t_String_int64_t_r_bool(bool * __result, int8_t * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int8_t * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(parse_string, rl_parse_string__int8_t_String_int64_t_r_bool, parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_string__int8_t_String_int64_t_r_bool(bool * __result, int8_t * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int8_t * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(can_parse_string, rl_can_parse_string__int8_t_String_int64_t_r_bool, can_parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_string__double_String_int64_t_r_bool(bool * __result, double * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(parse_string, rl_parse_string__double_String_int64_t_r_bool, parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_string__double_String_int64_t_r_bool(bool * __result, double * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(can_parse_string, rl_can_parse_string__double_String_int64_t_r_bool, can_parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_length__strlit_r_int64_t(int64_t * __result, char* * literal);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * literal
RLC_VISIT_FUNCTION(length, rl_length__strlit_r_int64_t, length, int64_t ,  literal)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_length__strlit_r_bool(bool * __result, char* * literal);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS char* * literal
RLC_VISIT_FUNCTION(can_length, rl_can_length__strlit_r_bool, can_length, bool ,  literal)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_string__String_String_int64_t_r_bool(bool * __result, union String * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union String * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(parse_string, rl_parse_string__String_String_int64_t_r_bool, String_parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_string__String_String_int64_t_r_bool(bool * __result, union String * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union String * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(can_parse_string, rl_can_parse_string__String_String_int64_t_r_bool, can_String_parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_parse_string__bool_String_int64_t_r_bool(bool * __result, bool * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS bool * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(parse_string, rl_parse_string__bool_String_int64_t_r_bool, parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_parse_string__bool_String_int64_t_r_bool(bool * __result, bool * result, union String * buffer, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS bool * result, union String * buffer, int64_t * index
RLC_VISIT_FUNCTION(can_parse_string, rl_can_parse_string__bool_String_int64_t_r_bool, can_parse_string, bool ,  result,  buffer,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__BIntT0T52T(union BIntT0T52T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BIntT0T52T * self
RLC_VISIT_FUNCTION(init, rl_m_init__BIntT0T52T, BInt_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__BIntT0T52T_r_bool(bool * __result, union BIntT0T52T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BIntT0T52T * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__BIntT0T52T_r_bool, can_BInt_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__BIntT0T14T(union BIntT0T14T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BIntT0T14T * self
RLC_VISIT_FUNCTION(init, rl_m_init__BIntT0T14T, BInt_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__BIntT0T14T_r_bool(bool * __result, union BIntT0T14T * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BIntT0T14T * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__BIntT0T14T_r_bool, can_BInt_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_equal__BIntT0T14T_int64_t_r_bool(bool * __result, union BIntT0T14T * self, int64_t * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * self, int64_t * other
RLC_VISIT_FUNCTION(equal, rl_m_equal__BIntT0T14T_int64_t_r_bool, BInt_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_equal__BIntT0T14T_int64_t_r_bool(bool * __result, union BIntT0T14T * self, int64_t * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * self, int64_t * other
RLC_VISIT_FUNCTION(can_equal, rl_m_can_equal__BIntT0T14T_int64_t_r_bool, can_BInt_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_less_equal__BIntT0T14T_int64_t_r_bool(bool * __result, union BIntT0T14T * self, int64_t * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * self, int64_t * other
RLC_VISIT_FUNCTION(less_equal, rl_m_less_equal__BIntT0T14T_int64_t_r_bool, BInt_less_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_less_equal__BIntT0T14T_int64_t_r_bool(bool * __result, union BIntT0T14T * self, int64_t * other);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * self, int64_t * other
RLC_VISIT_FUNCTION(can_less_equal, rl_m_can_less_equal__BIntT0T14T_int64_t_r_bool, can_BInt_less_equal, bool ,  self,  other)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_append_to_string__BIntT0T14T_String(union BIntT0T14T * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * to_add, union String * output
RLC_VISIT_FUNCTION(append_to_string, rl_append_to_string__BIntT0T14T_String, BInt_append_to_string, void ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_append_to_string__BIntT0T14T_String_r_bool(bool * __result, union BIntT0T14T * to_add, union String * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union BIntT0T14T * to_add, union String * output
RLC_VISIT_FUNCTION(can_append_to_string, rl_can_append_to_string__BIntT0T14T_String_r_bool, can_BInt_append_to_string, bool ,  to_add,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_max__int64_t_int64_t_r_int64_t(int64_t * __result, int64_t * a, int64_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * a, int64_t * b
RLC_VISIT_FUNCTION(max, rl_max__int64_t_int64_t_r_int64_t, max, int64_t ,  a,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_max__int64_t_int64_t_r_bool(bool * __result, int64_t * a, int64_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * a, int64_t * b
RLC_VISIT_FUNCTION(can_max, rl_can_max__int64_t_int64_t_r_bool, can_max, bool ,  a,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_min__int64_t_int64_t_r_int64_t(int64_t * __result, int64_t * a, int64_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * a, int64_t * b
RLC_VISIT_FUNCTION(min, rl_min__int64_t_int64_t_r_int64_t, min, int64_t ,  a,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_min__int64_t_int64_t_r_bool(bool * __result, int64_t * a, int64_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * a, int64_t * b
RLC_VISIT_FUNCTION(can_min, rl_can_min__int64_t_int64_t_r_bool, can_min, bool ,  a,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_sqrt__double_r_double(double * __result, double * f);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS double * f
RLC_VISIT_FUNCTION(sqrt, rl_sqrt__double_r_double, sqrt, double ,  f)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_sqrt__double_r_bool(bool * __result, double * f);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS double * f
RLC_VISIT_FUNCTION(can_sqrt, rl_can_sqrt__double_r_bool, can_sqrt, bool ,  f)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_abs__int64_t_r_int64_t(int64_t * __result, int64_t * a);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int64_t * a
RLC_VISIT_FUNCTION(abs, rl_abs__int64_t_r_int64_t, abs, int64_t ,  a)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_abs__int64_t_r_bool(bool * __result, int64_t * a);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int64_t * a
RLC_VISIT_FUNCTION(can_abs, rl_can_abs__int64_t_r_bool, can_abs, bool ,  a)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_near__double_double_double_r_bool(bool * __result, double * value, double * target, double * distance);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * value, double * target, double * distance
RLC_VISIT_FUNCTION(near, rl_near__double_double_double_r_bool, near, bool ,  value,  target,  distance)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_near__double_double_double_r_bool(bool * __result, double * value, double * target, double * distance);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * value, double * target, double * distance
RLC_VISIT_FUNCTION(can_near, rl_can_near__double_double_double_r_bool, can_near, bool ,  value,  target,  distance)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_custom_equal__int64_t_int64_t_r_bool(bool * __result, int64_t * lhs, int64_t * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * lhs, int64_t * rhs
RLC_VISIT_FUNCTION(custom_equal, rl_custom_equal__int64_t_int64_t_r_bool, custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_custom_equal__int64_t_int64_t_r_bool(bool * __result, int64_t * lhs, int64_t * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int64_t * lhs, int64_t * rhs
RLC_VISIT_FUNCTION(can_custom_equal, rl_can_custom_equal__int64_t_int64_t_r_bool, can_custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_custom_equal__bool_bool_r_bool(bool * __result, bool * lhs, bool * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * lhs, bool * rhs
RLC_VISIT_FUNCTION(custom_equal, rl_custom_equal__bool_bool_r_bool, custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_custom_equal__bool_bool_r_bool(bool * __result, bool * lhs, bool * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * lhs, bool * rhs
RLC_VISIT_FUNCTION(can_custom_equal, rl_can_custom_equal__bool_bool_r_bool, can_custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_custom_equal__int8_t_int8_t_r_bool(bool * __result, int8_t * lhs, int8_t * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int8_t * lhs, int8_t * rhs
RLC_VISIT_FUNCTION(custom_equal, rl_custom_equal__int8_t_int8_t_r_bool, custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_custom_equal__int8_t_int8_t_r_bool(bool * __result, int8_t * lhs, int8_t * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS int8_t * lhs, int8_t * rhs
RLC_VISIT_FUNCTION(can_custom_equal, rl_can_custom_equal__int8_t_int8_t_r_bool, can_custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_custom_equal__double_double_r_bool(bool * __result, double * lhs, double * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS double * lhs, double * rhs
RLC_VISIT_FUNCTION(custom_equal, rl_custom_equal__double_double_r_bool, custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_custom_equal__double_double_r_bool(bool * __result, double * lhs, double * rhs);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS double * lhs, double * rhs
RLC_VISIT_FUNCTION(can_custom_equal, rl_can_custom_equal__double_double_r_bool, can_custom_equal, bool ,  lhs,  rhs)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_enumerate__bool_VectorTboolT(bool * b, union VectorTboolT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * b, union VectorTboolT * output
RLC_VISIT_FUNCTION(enumerate, rl_enumerate__bool_VectorTboolT, enumerate, void ,  b,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_enumerate__bool_VectorTboolT_r_bool(bool * __result, bool * b, union VectorTboolT * output);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS bool * b, union VectorTboolT * output
RLC_VISIT_FUNCTION(can_enumerate, rl_can_enumerate__bool_VectorTboolT_r_bool, can_enumerate, bool ,  b,  output)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_enumeration_error__int64_t_String_VectorTStringT(int64_t * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(enumeration_error, rl_enumeration_error__int64_t_String_VectorTStringT, enumeration_error, void ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_enumeration_error__int64_t_String_VectorTStringT_r_bool(bool * __result, int64_t * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(can_enumeration_error, rl_can_enumeration_error__int64_t_String_VectorTStringT_r_bool, can_enumeration_error, bool ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_enumeration_error__double_String_VectorTStringT(double * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(enumeration_error, rl_enumeration_error__double_String_VectorTStringT, enumeration_error, void ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_enumeration_error__double_String_VectorTStringT_r_bool(bool * __result, double * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(can_enumeration_error, rl_can_enumeration_error__double_String_VectorTStringT_r_bool, can_enumeration_error, bool ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_write_in_observation_tensor__int64_t_int64_t_int64_t_VectorTdoubleT_int64_t(int64_t * value, int64_t * min, int64_t * max, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 5
#define RLC_ARGUMENTS int64_t * value, int64_t * min, int64_t * max, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(write_in_observation_tensor, rl_write_in_observation_tensor__int64_t_int64_t_int64_t_VectorTdoubleT_int64_t, write_in_observation_tensor, void ,  value,  min,  max,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_write_in_observation_tensor__int64_t_int64_t_int64_t_VectorTdoubleT_int64_t_r_bool(bool * __result, int64_t * value, int64_t * min, int64_t * max, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 5
#define RLC_ARGUMENTS int64_t * value, int64_t * min, int64_t * max, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(can_write_in_observation_tensor, rl_can_write_in_observation_tensor__int64_t_int64_t_int64_t_VectorTdoubleT_int64_t_r_bool, can_write_in_observation_tensor, bool ,  value,  min,  max,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_write_in_observation_tensor__int64_t_int64_t_VectorTdoubleT_int64_t(int64_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS int64_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(write_in_observation_tensor, rl_write_in_observation_tensor__int64_t_int64_t_VectorTdoubleT_int64_t, write_in_observation_tensor, void ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_write_in_observation_tensor__int64_t_int64_t_VectorTdoubleT_int64_t_r_bool(bool * __result, int64_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS int64_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(can_write_in_observation_tensor, rl_can_write_in_observation_tensor__int64_t_int64_t_VectorTdoubleT_int64_t_r_bool, can_write_in_observation_tensor, bool ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_size_as_observation_tensor__int64_t_r_int64_t(int64_t * __result, int64_t * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int64_t * obj
RLC_VISIT_FUNCTION(size_as_observation_tensor, rl_size_as_observation_tensor__int64_t_r_int64_t, size_as_observation_tensor, int64_t ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_size_as_observation_tensor__int64_t_r_bool(bool * __result, int64_t * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int64_t * obj
RLC_VISIT_FUNCTION(can_size_as_observation_tensor, rl_can_size_as_observation_tensor__int64_t_r_bool, can_size_as_observation_tensor, bool ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_write_in_observation_tensor__double_int64_t_VectorTdoubleT_int64_t(double * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS double * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(write_in_observation_tensor, rl_write_in_observation_tensor__double_int64_t_VectorTdoubleT_int64_t, write_in_observation_tensor, void ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_write_in_observation_tensor__double_int64_t_VectorTdoubleT_int64_t_r_bool(bool * __result, double * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS double * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(can_write_in_observation_tensor, rl_can_write_in_observation_tensor__double_int64_t_VectorTdoubleT_int64_t_r_bool, can_write_in_observation_tensor, bool ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_size_as_observation_tensor__double_r_int64_t(int64_t * __result, double * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS double * obj
RLC_VISIT_FUNCTION(size_as_observation_tensor, rl_size_as_observation_tensor__double_r_int64_t, size_as_observation_tensor, int64_t ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_size_as_observation_tensor__double_r_bool(bool * __result, double * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS double * obj
RLC_VISIT_FUNCTION(can_size_as_observation_tensor, rl_can_size_as_observation_tensor__double_r_bool, can_size_as_observation_tensor, bool ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_write_in_observation_tensor__bool_int64_t_VectorTdoubleT_int64_t(bool * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS bool * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(write_in_observation_tensor, rl_write_in_observation_tensor__bool_int64_t_VectorTdoubleT_int64_t, write_in_observation_tensor, void ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_write_in_observation_tensor__bool_int64_t_VectorTdoubleT_int64_t_r_bool(bool * __result, bool * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS bool * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(can_write_in_observation_tensor, rl_can_write_in_observation_tensor__bool_int64_t_VectorTdoubleT_int64_t_r_bool, can_write_in_observation_tensor, bool ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_size_as_observation_tensor__bool_r_int64_t(int64_t * __result, bool * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS bool * obj
RLC_VISIT_FUNCTION(size_as_observation_tensor, rl_size_as_observation_tensor__bool_r_int64_t, size_as_observation_tensor, int64_t ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_size_as_observation_tensor__bool_r_bool(bool * __result, bool * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS bool * obj
RLC_VISIT_FUNCTION(can_size_as_observation_tensor, rl_can_size_as_observation_tensor__bool_r_bool, can_size_as_observation_tensor, bool ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_write_in_observation_tensor__int8_t_int64_t_VectorTdoubleT_int64_t(int8_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS int8_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(write_in_observation_tensor, rl_write_in_observation_tensor__int8_t_int64_t_VectorTdoubleT_int64_t, write_in_observation_tensor, void ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_write_in_observation_tensor__int8_t_int64_t_VectorTdoubleT_int64_t_r_bool(bool * __result, int8_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 4
#define RLC_ARGUMENTS int8_t * obj, int64_t * observer_id, union VectorTdoubleT * output, int64_t * index
RLC_VISIT_FUNCTION(can_write_in_observation_tensor, rl_can_write_in_observation_tensor__int8_t_int64_t_VectorTdoubleT_int64_t_r_bool, can_write_in_observation_tensor, bool ,  obj,  observer_id,  output,  index)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_size_as_observation_tensor__int8_t_r_int64_t(int64_t * __result, int8_t * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * obj
RLC_VISIT_FUNCTION(size_as_observation_tensor, rl_size_as_observation_tensor__int8_t_r_int64_t, size_as_observation_tensor, int64_t ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_size_as_observation_tensor__int8_t_r_bool(bool * __result, int8_t * obj);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS int8_t * obj
RLC_VISIT_FUNCTION(can_size_as_observation_tensor, rl_can_size_as_observation_tensor__int8_t_r_bool, can_size_as_observation_tensor, bool ,  obj)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_write_tensor_warning_context__String_VectorTStringT(union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(write_tensor_warning_context, rl_write_tensor_warning_context__String_VectorTStringT, String_write_tensor_warning_context, void ,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_write_tensor_warning_context__String_VectorTStringT_r_bool(bool * __result, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(can_write_tensor_warning_context, rl_can_write_tensor_warning_context__String_VectorTStringT_r_bool, can_String_write_tensor_warning_context, bool ,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_tensorable_warning__int64_t_String_VectorTStringT(int64_t * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(tensorable_warning, rl_tensorable_warning__int64_t_String_VectorTStringT, tensorable_warning, void ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_tensorable_warning__int64_t_String_VectorTStringT_r_bool(bool * __result, int64_t * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS int64_t * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(can_tensorable_warning, rl_can_tensorable_warning__int64_t_String_VectorTStringT_r_bool, can_tensorable_warning, bool ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_tensorable_warning__double_String_VectorTStringT(double * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(tensorable_warning, rl_tensorable_warning__double_String_VectorTStringT, tensorable_warning, void ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_tensorable_warning__double_String_VectorTStringT_r_bool(bool * __result, double * x, union String * out, union VectorTStringT * context);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS double * x, union String * out, union VectorTStringT * context
RLC_VISIT_FUNCTION(can_tensorable_warning, rl_can_tensorable_warning__double_String_VectorTStringT_r_bool, can_tensorable_warning, bool ,  x,  out,  context)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_init__Deck(union Deck * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Deck * self
RLC_VISIT_FUNCTION(init, rl_m_init__Deck, Deck_init, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_init__Deck_r_bool(bool * __result, union Deck * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Deck * self
RLC_VISIT_FUNCTION(can_init, rl_m_can_init__Deck_r_bool, can_Deck_init, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_switch_cards__Deck_int64_t_int64_t(union Deck * self, int64_t * a, int64_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union Deck * self, int64_t * a, int64_t * b
RLC_VISIT_FUNCTION(switch_cards, rl_m_switch_cards__Deck_int64_t_int64_t, Deck_switch_cards, void ,  self,  a,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_switch_cards__Deck_int64_t_int64_t_r_bool(bool * __result, union Deck * self, int64_t * a, int64_t * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union Deck * self, int64_t * a, int64_t * b
RLC_VISIT_FUNCTION(can_switch_cards, rl_m_can_switch_cards__Deck_int64_t_int64_t_r_bool, can_Deck_switch_cards, bool ,  self,  a,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_draw__Deck_BoundedVectorTBIntT0T14TT20T(union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand
RLC_VISIT_FUNCTION(draw, rl_draw__Deck_BoundedVectorTBIntT0T14TT20T, Deck_draw, void ,  deck,  hand)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_draw__Deck_BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand
RLC_VISIT_FUNCTION(can_draw, rl_can_draw__Deck_BoundedVectorTBIntT0T14TT20T_r_bool, can_Deck_draw, bool ,  deck,  hand)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_deal__Deck_BoundedVectorTBIntT0T14TT20T(union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand
RLC_VISIT_FUNCTION(deal, rl_deal__Deck_BoundedVectorTBIntT0T14TT20T, Deck_deal, void ,  deck,  hand)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_deal__Deck_BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Deck * deck, union BoundedVectorTBIntT0T14TT20T * hand
RLC_VISIT_FUNCTION(can_deal, rl_can_deal__Deck_BoundedVectorTBIntT0T14TT20T_r_bool, can_Deck_deal, bool ,  deck,  hand)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_calculate_points__BoundedVectorTBIntT0T14TT20T_r_int64_t(int64_t * __result, union BoundedVectorTBIntT0T14TT20T * hand);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * hand
RLC_VISIT_FUNCTION(calculate_points, rl_calculate_points__BoundedVectorTBIntT0T14TT20T_r_int64_t, BoundedVector_calculate_points, int64_t ,  hand)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_calculate_points__BoundedVectorTBIntT0T14TT20T_r_bool(bool * __result, union BoundedVectorTBIntT0T14TT20T * hand);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union BoundedVectorTBIntT0T14TT20T * hand
RLC_VISIT_FUNCTION(can_calculate_points, rl_can_calculate_points__BoundedVectorTBIntT0T14TT20T_r_bool, can_BoundedVector_calculate_points, bool ,  hand)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_apply__GameShuffleSource_Game(union GameShuffleSource * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleSource * self, union Game * frame
RLC_VISIT_FUNCTION(apply, rl_apply__GameShuffleSource_Game, GameShuffleSource_apply, void ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_apply__GameShuffleSource_Game_r_bool(bool * __result, union GameShuffleSource * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleSource * self, union Game * frame
RLC_VISIT_FUNCTION(can_apply, rl_can_apply__GameShuffleSource_Game_r_bool, can_GameShuffleSource_apply, bool ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_get_type_name__GameShuffleSource_r_strlit(char* * __result, union GameShuffleSource * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleSource * self
RLC_VISIT_FUNCTION(get_type_name, rl_get_type_name__GameShuffleSource_r_strlit, GameShuffleSource_get_type_name, char* ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_get_type_name__GameShuffleSource_r_bool(bool * __result, union GameShuffleSource * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleSource * self
RLC_VISIT_FUNCTION(can_get_type_name, rl_can_get_type_name__GameShuffleSource_r_bool, can_GameShuffleSource_get_type_name, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_apply__GameShuffleTarget_Game(union GameShuffleTarget * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleTarget * self, union Game * frame
RLC_VISIT_FUNCTION(apply, rl_apply__GameShuffleTarget_Game, GameShuffleTarget_apply, void ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_apply__GameShuffleTarget_Game_r_bool(bool * __result, union GameShuffleTarget * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameShuffleTarget * self, union Game * frame
RLC_VISIT_FUNCTION(can_apply, rl_can_apply__GameShuffleTarget_Game_r_bool, can_GameShuffleTarget_apply, bool ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_get_type_name__GameShuffleTarget_r_strlit(char* * __result, union GameShuffleTarget * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleTarget * self
RLC_VISIT_FUNCTION(get_type_name, rl_get_type_name__GameShuffleTarget_r_strlit, GameShuffleTarget_get_type_name, char* ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_get_type_name__GameShuffleTarget_r_bool(bool * __result, union GameShuffleTarget * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameShuffleTarget * self
RLC_VISIT_FUNCTION(can_get_type_name, rl_can_get_type_name__GameShuffleTarget_r_bool, can_GameShuffleTarget_get_type_name, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_apply__GameHit_Game(union GameHit * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameHit * self, union Game * frame
RLC_VISIT_FUNCTION(apply, rl_apply__GameHit_Game, GameHit_apply, void ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_apply__GameHit_Game_r_bool(bool * __result, union GameHit * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameHit * self, union Game * frame
RLC_VISIT_FUNCTION(can_apply, rl_can_apply__GameHit_Game_r_bool, can_GameHit_apply, bool ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_get_type_name__GameHit_r_strlit(char* * __result, union GameHit * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameHit * self
RLC_VISIT_FUNCTION(get_type_name, rl_get_type_name__GameHit_r_strlit, GameHit_get_type_name, char* ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_get_type_name__GameHit_r_bool(bool * __result, union GameHit * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameHit * self
RLC_VISIT_FUNCTION(can_get_type_name, rl_can_get_type_name__GameHit_r_bool, can_GameHit_get_type_name, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_apply__GameStand_Game(union GameStand * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameStand * self, union Game * frame
RLC_VISIT_FUNCTION(apply, rl_apply__GameStand_Game, GameStand_apply, void ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_apply__GameStand_Game_r_bool(bool * __result, union GameStand * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union GameStand * self, union Game * frame
RLC_VISIT_FUNCTION(can_apply, rl_can_apply__GameStand_Game_r_bool, can_GameStand_apply, bool ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_get_type_name__GameStand_r_strlit(char* * __result, union GameStand * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameStand * self
RLC_VISIT_FUNCTION(get_type_name, rl_get_type_name__GameStand_r_strlit, GameStand_get_type_name, char* ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_get_type_name__GameStand_r_bool(bool * __result, union GameStand * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union GameStand * self
RLC_VISIT_FUNCTION(can_get_type_name, rl_can_get_type_name__GameStand_r_bool, can_GameStand_get_type_name, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_apply__AnyGameAction_Game(struct AnyGameAction * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union Game * frame
RLC_VISIT_FUNCTION(apply, rl_apply__AnyGameAction_Game, apply, void ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_apply__AnyGameAction_Game_r_bool(bool * __result, struct AnyGameAction * self, union Game * frame);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS struct AnyGameAction * self, union Game * frame
RLC_VISIT_FUNCTION(can_apply, rl_can_apply__AnyGameAction_Game_r_bool, can_apply, bool ,  self,  frame)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_get_current_player__Game_r_int64_t(int64_t * __result, union Game * g);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * g
RLC_VISIT_FUNCTION(get_current_player, rl_get_current_player__Game_r_int64_t, Game_get_current_player, int64_t ,  g)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_get_current_player__Game_r_bool(bool * __result, union Game * g);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * g
RLC_VISIT_FUNCTION(can_get_current_player, rl_can_get_current_player__Game_r_bool, can_Game_get_current_player, bool ,  g)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_get_num_players__r_int64_t(int64_t * __result);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 0
#define RLC_ARGUMENTS 
RLC_VISIT_FUNCTION(get_num_players, rl_get_num_players__r_int64_t, get_num_players, int64_t , )
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_get_num_players__r_bool(bool * __result);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 0
#define RLC_ARGUMENTS 
RLC_VISIT_FUNCTION(can_get_num_players, rl_can_get_num_players__r_bool, can_get_num_players, bool , )
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_score__Game_int64_t_r_double(double * __result, union Game * g, int64_t * player_id);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * g, int64_t * player_id
RLC_VISIT_FUNCTION(score, rl_score__Game_int64_t_r_double, Game_score, double ,  g,  player_id)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_score__Game_int64_t_r_bool(bool * __result, union Game * g, int64_t * player_id);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * g, int64_t * player_id
RLC_VISIT_FUNCTION(can_score, rl_can_score__Game_int64_t_r_bool, can_Game_score, bool ,  g,  player_id)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_pretty_print__Game(union Game * g);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * g
RLC_VISIT_FUNCTION(pretty_print, rl_pretty_print__Game, Game_pretty_print, void ,  g)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_pretty_print__Game_r_bool(bool * __result, union Game * g);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * g
RLC_VISIT_FUNCTION(can_pretty_print, rl_can_pretty_print__Game_r_bool, can_Game_pretty_print, bool ,  g)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_play__r_Game(union Game * __result);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 0
#define RLC_ARGUMENTS 
RLC_VISIT_FUNCTION(play, rl_play__r_Game, Game_play, union Game , )
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_play__r_bool(bool * __result);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 0
#define RLC_ARGUMENTS 
RLC_VISIT_FUNCTION(can_play, rl_can_play__r_bool, can_Game_play, bool , )
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_shuffle_source__Game_BIntT0T52T(union Game * self, union BIntT0T52T * a);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * self, union BIntT0T52T * a
RLC_VISIT_FUNCTION(shuffle_source, rl_m_shuffle_source__Game_BIntT0T52T, Game_shuffle_source, void ,  self,  a)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_shuffle_source__Game_BIntT0T52T_r_bool(bool * __result, union Game * self, union BIntT0T52T * a);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * self, union BIntT0T52T * a
RLC_VISIT_FUNCTION(can_shuffle_source, rl_m_can_shuffle_source__Game_BIntT0T52T_r_bool, can_Game_shuffle_source, bool ,  self,  a)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_shuffle_target__Game_BIntT0T52T(union Game * self, union BIntT0T52T * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * self, union BIntT0T52T * b
RLC_VISIT_FUNCTION(shuffle_target, rl_m_shuffle_target__Game_BIntT0T52T, Game_shuffle_target, void ,  self,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_shuffle_target__Game_BIntT0T52T_r_bool(bool * __result, union Game * self, union BIntT0T52T * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 2
#define RLC_ARGUMENTS union Game * self, union BIntT0T52T * b
RLC_VISIT_FUNCTION(can_shuffle_target, rl_m_can_shuffle_target__Game_BIntT0T52T_r_bool, can_Game_shuffle_target, bool ,  self,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_hit__Game(union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(hit, rl_m_hit__Game, Game_hit, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_hit__Game_r_bool(bool * __result, union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(can_hit, rl_m_can_hit__Game_r_bool, can_Game_hit, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_stand__Game(union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(stand, rl_m_stand__Game, Game_stand, void ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_stand__Game_r_bool(bool * __result, union Game * self);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * self
RLC_VISIT_FUNCTION(can_stand, rl_m_can_stand__Game_r_bool, can_Game_stand, bool ,  self)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_is_done__Game_r_bool(bool * __result, union Game * arg0);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * arg0
RLC_VISIT_FUNCTION(is_done, rl_m_is_done__Game_r_bool, Game_is_done, bool ,  arg0)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_is_done__Game_r_bool(bool * __result, union Game * arg0);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Game * arg0
RLC_VISIT_FUNCTION(can_is_done, rl_m_can_is_done__Game_r_bool, can_Game_is_done, bool ,  arg0)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_shuffle__Deck_r_Shuffle(union Shuffle * __result, union Deck * deck);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Deck * deck
RLC_VISIT_FUNCTION(shuffle, rl_shuffle__Deck_r_Shuffle, Shuffle_shuffle, union Shuffle ,  deck)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_can_shuffle__Deck_r_bool(bool * __result, union Deck * deck);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Deck * deck
RLC_VISIT_FUNCTION(can_shuffle, rl_can_shuffle__Deck_r_bool, can_Shuffle_shuffle, bool ,  deck)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_shuffle_source__Shuffle_Deck_BIntT0T52T(union Shuffle * self, union Deck * deck, union BIntT0T52T * a);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union Shuffle * self, union Deck * deck, union BIntT0T52T * a
RLC_VISIT_FUNCTION(shuffle_source, rl_m_shuffle_source__Shuffle_Deck_BIntT0T52T, Shuffle_shuffle_source, void ,  self,  deck,  a)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_shuffle_source__Shuffle_Deck_BIntT0T52T_r_bool(bool * __result, union Shuffle * self, union Deck * deck, union BIntT0T52T * a);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union Shuffle * self, union Deck * deck, union BIntT0T52T * a
RLC_VISIT_FUNCTION(can_shuffle_source, rl_m_can_shuffle_source__Shuffle_Deck_BIntT0T52T_r_bool, can_Shuffle_shuffle_source, bool ,  self,  deck,  a)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_shuffle_target__Shuffle_Deck_BIntT0T52T(union Shuffle * self, union Deck * deck, union BIntT0T52T * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union Shuffle * self, union Deck * deck, union BIntT0T52T * b
RLC_VISIT_FUNCTION(shuffle_target, rl_m_shuffle_target__Shuffle_Deck_BIntT0T52T, Shuffle_shuffle_target, void ,  self,  deck,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_shuffle_target__Shuffle_Deck_BIntT0T52T_r_bool(bool * __result, union Shuffle * self, union Deck * deck, union BIntT0T52T * b);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 3
#define RLC_ARGUMENTS union Shuffle * self, union Deck * deck, union BIntT0T52T * b
RLC_VISIT_FUNCTION(can_shuffle_target, rl_m_can_shuffle_target__Shuffle_Deck_BIntT0T52T_r_bool, can_Shuffle_shuffle_target, bool ,  self,  deck,  b)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_is_done__Shuffle_r_bool(bool * __result, union Shuffle * arg0);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Shuffle * arg0
RLC_VISIT_FUNCTION(is_done, rl_m_is_done__Shuffle_r_bool, Shuffle_is_done, bool ,  arg0)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
void rl_m_can_is_done__Shuffle_r_bool(bool * __result, union Shuffle * arg0);
#endif

#ifdef RLC_VISIT_FUNCTION
#define RLC_ARGUMENTS_COUNT 1
#define RLC_ARGUMENTS union Shuffle * arg0
RLC_VISIT_FUNCTION(can_is_done, rl_m_can_is_done__Shuffle_r_bool, can_Shuffle_is_done, bool ,  arg0)
#undef RLC_ARGUMENTS_COUNT
#undef RLC_ARGUMENTS
#endif

#ifdef RLC_GET_FUNCTION_DECLS
#undef RLC_GET_FUNCTION_DECLS
#endif

#ifdef RLC_VISIT_FUNCTION
#undef RLC_VISIT_FUNCTION
#endif
#ifdef RLC_GET_TYPE_DEFS
typedef union BIntT0T14T {
struct _ContentBIntT0T14T {
    int64_t value;
  } content;
#ifdef __cplusplus
BIntT0T14T& operator=(union BIntT0T14T(& other));
bool less_equal(int64_t(& other));
bool operator==(int64_t(& other));
BIntT0T14T();
BIntT0T14T(const BIntT0T14T& other) : BIntT0T14T() {*this = const_cast<BIntT0T14T&>(other);}
BIntT0T14T(BIntT0T14T&& other) = delete;
BIntT0T14T& operator=(BIntT0T14T&& other) = delete;
~BIntT0T14T() {}
#endif
} BIntT0T14T;
typedef union VectorTBIntT0T14TT {
struct _ContentVectorTBIntT0T14TT {
    union BIntT0T14T* _data;
    int64_t _size;
    int64_t _capacity;
  } content;
#ifdef __cplusplus
void append(union BIntT0T14T(& value));
union BIntT0T14T* get(int64_t(& index));
int64_t size();
VectorTBIntT0T14TT();
union BIntT0T14T pop();
~VectorTBIntT0T14TT();
VectorTBIntT0T14TT& operator=(union VectorTBIntT0T14TT(& other));
void set(int64_t(& index), union BIntT0T14T(& value));
VectorTBIntT0T14TT(const VectorTBIntT0T14TT& other) : VectorTBIntT0T14TT() {*this = const_cast<VectorTBIntT0T14TT&>(other);}
VectorTBIntT0T14TT(VectorTBIntT0T14TT&& other) = delete;
VectorTBIntT0T14TT& operator=(VectorTBIntT0T14TT&& other) = delete;
#endif
} VectorTBIntT0T14TT;
typedef union Deck {
struct _ContentDeck {
    union VectorTBIntT0T14TT cards;
  } content;
#ifdef __cplusplus
~Deck();
Deck& operator=(union Deck(& other));
void switch_cards(int64_t(& a), int64_t(& b));
Deck();
Deck(const Deck& other) : Deck() {*this = const_cast<Deck&>(other);}
Deck(Deck&& other) = delete;
Deck& operator=(Deck&& other) = delete;
#endif
} Deck;
typedef union HiddenTDeckT {
struct _ContentHiddenTDeckT {
    union Deck value;
  } content;
#ifdef __cplusplus
HiddenTDeckT();
HiddenTDeckT& operator=(union HiddenTDeckT(& other));
~HiddenTDeckT();
HiddenTDeckT(const HiddenTDeckT& other) : HiddenTDeckT() {*this = const_cast<HiddenTDeckT&>(other);}
HiddenTDeckT(HiddenTDeckT&& other) = delete;
HiddenTDeckT& operator=(HiddenTDeckT&& other) = delete;
#endif
} HiddenTDeckT;
typedef union BoundedVectorTBIntT0T14TT20T {
struct _ContentBoundedVectorTBIntT0T14TT20T {
    union VectorTBIntT0T14TT _data;
  } content;
#ifdef __cplusplus
int64_t size();
union BIntT0T14T* get(int64_t(& index));
void append(union BIntT0T14T(& value));
~BoundedVectorTBIntT0T14TT20T();
BoundedVectorTBIntT0T14TT20T();
BoundedVectorTBIntT0T14TT20T& operator=(union BoundedVectorTBIntT0T14TT20T(& other));
BoundedVectorTBIntT0T14TT20T(const BoundedVectorTBIntT0T14TT20T& other) : BoundedVectorTBIntT0T14TT20T() {*this = const_cast<BoundedVectorTBIntT0T14TT20T&>(other);}
BoundedVectorTBIntT0T14TT20T(BoundedVectorTBIntT0T14TT20T&& other) = delete;
BoundedVectorTBIntT0T14TT20T& operator=(BoundedVectorTBIntT0T14TT20T&& other) = delete;
#endif
} BoundedVectorTBIntT0T14TT20T;
typedef union HiddenTBoundedVectorTBIntT0T14TT20TT {
struct _ContentHiddenTBoundedVectorTBIntT0T14TT20TT {
    union BoundedVectorTBIntT0T14TT20T value;
  } content;
#ifdef __cplusplus
HiddenTBoundedVectorTBIntT0T14TT20TT();
~HiddenTBoundedVectorTBIntT0T14TT20TT();
HiddenTBoundedVectorTBIntT0T14TT20TT& operator=(union HiddenTBoundedVectorTBIntT0T14TT20TT(& other));
HiddenTBoundedVectorTBIntT0T14TT20TT(const HiddenTBoundedVectorTBIntT0T14TT20TT& other) : HiddenTBoundedVectorTBIntT0T14TT20TT() {*this = const_cast<HiddenTBoundedVectorTBIntT0T14TT20TT&>(other);}
HiddenTBoundedVectorTBIntT0T14TT20TT(HiddenTBoundedVectorTBIntT0T14TT20TT&& other) = delete;
HiddenTBoundedVectorTBIntT0T14TT20TT& operator=(HiddenTBoundedVectorTBIntT0T14TT20TT&& other) = delete;
#endif
} HiddenTBoundedVectorTBIntT0T14TT20TT;
typedef union VectorTboolT {
struct _ContentVectorTboolT {
    bool* _data;
    int64_t _size;
    int64_t _capacity;
  } content;
#ifdef __cplusplus
void append(bool(& value));
bool* get(int64_t(& index));
VectorTboolT& operator=(union VectorTboolT(& other));
~VectorTboolT();
VectorTboolT();
VectorTboolT(const VectorTboolT& other) : VectorTboolT() {*this = const_cast<VectorTboolT&>(other);}
VectorTboolT(VectorTboolT&& other) = delete;
VectorTboolT& operator=(VectorTboolT&& other) = delete;
#endif
} VectorTboolT;
typedef union VectorTint8_tT {
struct _ContentVectorTint8_tT {
    int8_t* _data;
    int64_t _size;
    int64_t _capacity;
  } content;
#ifdef __cplusplus
int8_t* get(int64_t(& index));
void drop_back(int64_t(& quantity));
VectorTint8_tT();
void append(int8_t(& value));
int8_t* back();
VectorTint8_tT& operator=(union VectorTint8_tT(& other));
~VectorTint8_tT();
int64_t size();
int8_t pop();
VectorTint8_tT(const VectorTint8_tT& other) : VectorTint8_tT() {*this = const_cast<VectorTint8_tT&>(other);}
VectorTint8_tT(VectorTint8_tT&& other) = delete;
VectorTint8_tT& operator=(VectorTint8_tT&& other) = delete;
#endif
} VectorTint8_tT;
typedef union String {
struct _ContentString {
    union VectorTint8_tT _data;
  } content;
#ifdef __cplusplus
int64_t size();
bool not_equal(char*(& other));
bool not_equal(union String(& other));
void drop_back(int64_t(& quantity));
String();
void reverse();
bool substring_matches(char*(& lit), int64_t(& pos));
void append(int8_t(& b));
void append_quoted(union String(& str));
union String to_indented_lines();
String& operator=(union String(& other));
int64_t count(int8_t(& b));
void append(char*(& str));
union String add(union String(& other));
int8_t* get(int64_t(& index));
int8_t* back();
void append(union String(& str));
bool operator==(char*(& other));
~String();
bool operator==(union String(& other));
String(const String& other) : String() {*this = const_cast<String&>(other);}
String(String&& other) = delete;
String& operator=(String&& other) = delete;
#endif
} String;
typedef union VectorTStringT {
struct _ContentVectorTStringT {
    union String* _data;
    int64_t _size;
    int64_t _capacity;
  } content;
#ifdef __cplusplus
VectorTStringT& operator=(union VectorTStringT(& other));
~VectorTStringT();
union String pop();
VectorTStringT();
void append(union String(& value));
union String* get(int64_t(& index));
int64_t size();
VectorTStringT(const VectorTStringT& other) : VectorTStringT() {*this = const_cast<VectorTStringT&>(other);}
VectorTStringT(VectorTStringT&& other) = delete;
VectorTStringT& operator=(VectorTStringT&& other) = delete;
#endif
} VectorTStringT;
typedef union VectorTdoubleT {
struct _ContentVectorTdoubleT {
    double* _data;
    int64_t _size;
    int64_t _capacity;
  } content;
#ifdef __cplusplus
int64_t size();
void resize(int64_t(& new_size));
double pop();
double* get(int64_t(& index));
VectorTdoubleT& operator=(union VectorTdoubleT(& other));
~VectorTdoubleT();
VectorTdoubleT();
void append(double(& value));
VectorTdoubleT(const VectorTdoubleT& other) : VectorTdoubleT() {*this = const_cast<VectorTdoubleT&>(other);}
VectorTdoubleT(VectorTdoubleT&& other) = delete;
VectorTdoubleT& operator=(VectorTdoubleT&& other) = delete;
#endif
} VectorTdoubleT;
typedef union BIntT0T52T {
struct _ContentBIntT0T52T {
    int64_t value;
  } content;
#ifdef __cplusplus
BIntT0T52T();
BIntT0T52T& operator=(union BIntT0T52T(& other));
BIntT0T52T(const BIntT0T52T& other) : BIntT0T52T() {*this = const_cast<BIntT0T52T&>(other);}
BIntT0T52T(BIntT0T52T&& other) = delete;
BIntT0T52T& operator=(BIntT0T52T&& other) = delete;
~BIntT0T52T() {}
#endif
} BIntT0T52T;
typedef union GameShuffleSource {
struct _ContentGameShuffleSource {
    union BIntT0T52T a;
  } content;
#ifdef __cplusplus
GameShuffleSource();
GameShuffleSource& operator=(union GameShuffleSource(& other));
GameShuffleSource(const GameShuffleSource& other) : GameShuffleSource() {*this = const_cast<GameShuffleSource&>(other);}
GameShuffleSource(GameShuffleSource&& other) = delete;
GameShuffleSource& operator=(GameShuffleSource&& other) = delete;
~GameShuffleSource() {}
#endif
} GameShuffleSource;
typedef union GameShuffleTarget {
struct _ContentGameShuffleTarget {
    union BIntT0T52T b;
  } content;
#ifdef __cplusplus
GameShuffleTarget();
GameShuffleTarget& operator=(union GameShuffleTarget(& other));
GameShuffleTarget(const GameShuffleTarget& other) : GameShuffleTarget() {*this = const_cast<GameShuffleTarget&>(other);}
GameShuffleTarget(GameShuffleTarget&& other) = delete;
GameShuffleTarget& operator=(GameShuffleTarget&& other) = delete;
~GameShuffleTarget() {}
#endif
} GameShuffleTarget;
typedef union GameHit {
struct _ContentGameHit {
  } content;
#ifdef __cplusplus
GameHit();
GameHit& operator=(union GameHit(& other));
GameHit(const GameHit& other) : GameHit() {*this = const_cast<GameHit&>(other);}
GameHit(GameHit&& other) = delete;
GameHit& operator=(GameHit&& other) = delete;
~GameHit() {}
#endif
} GameHit;
typedef union GameStand {
struct _ContentGameStand {
  } content;
#ifdef __cplusplus
GameStand();
GameStand& operator=(union GameStand(& other));
GameStand(const GameStand& other) : GameStand() {*this = const_cast<GameStand&>(other);}
GameStand(GameStand&& other) = delete;
GameStand& operator=(GameStand&& other) = delete;
~GameStand() {}
#endif
} GameStand;
typedef union Shuffle {
struct _ContentShuffle {
    int64_t resume_index;
    int64_t to_shuffle;
    union BIntT0T52T a;
  } content;
#ifdef __cplusplus
Shuffle();
Shuffle& operator=(union Shuffle(& other));
bool is_done();
void shuffle_source(union Deck(& deck), union BIntT0T52T(& a));
bool can_shuffle_source(union Deck(& deck), union BIntT0T52T(& a));
void shuffle_target(union Deck(& deck), union BIntT0T52T(& b));
bool can_shuffle_target(union Deck(& deck), union BIntT0T52T(& b));
Shuffle(const Shuffle& other) : Shuffle() {*this = const_cast<Shuffle&>(other);}
Shuffle(Shuffle&& other) = delete;
Shuffle& operator=(Shuffle&& other) = delete;
~Shuffle() {}
#endif
} Shuffle;
typedef union Game {
struct _ContentGame {
    int64_t resume_index;
    union HiddenTDeckT deck;
    union BoundedVectorTBIntT0T14TT20T player_hand;
    union HiddenTBoundedVectorTBIntT0T14TT20TT dealer_hand;
    union Shuffle shuffling;
    bool player_passed;
    bool player_bust;
  } content;
#ifdef __cplusplus
Game& operator=(union Game(& other));
bool is_done();
void shuffle_source(union BIntT0T52T(& a));
bool can_shuffle_source(union BIntT0T52T(& a));
void shuffle_target(union BIntT0T52T(& b));
bool can_shuffle_target(union BIntT0T52T(& b));
void hit();
bool can_hit();
void stand();
bool can_stand();
Game();
~Game();
Game(const Game& other) : Game() {*this = const_cast<Game&>(other);}
Game(Game&& other) = delete;
Game& operator=(Game&& other) = delete;
#endif
} Game;
struct AnyGameAction {
  union _ContentAnyGameAction{
    #ifdef __cplusplus
_ContentAnyGameAction() {};
~_ContentAnyGameAction() {};
#endif
    union GameShuffleSource field0;
    union GameShuffleTarget field1;
    union GameHit field2;
    union GameStand field3;
  } content;
  int64_t active_index;
#ifdef __cplusplus
void operator=(union GameStand(& other));
void operator=(union GameShuffleTarget(& other));
AnyGameAction();
AnyGameAction& operator=(struct AnyGameAction(& other));
void operator=(union GameShuffleSource(& other));
void operator=(union GameHit(& other));
AnyGameAction(const AnyGameAction& other) : AnyGameAction() {*this = const_cast<AnyGameAction&>(other);}
AnyGameAction(AnyGameAction&& other) = delete;
AnyGameAction& operator=(AnyGameAction&& other) = delete;
~AnyGameAction() {}
#endif
};
#ifdef __cplusplus
}
#endif
#ifdef __cplusplus
inline Game& Game::operator=(union Game(& other)) {
 rl_m_assign__Game_Game(this, &other);
return *this;
}
inline bool Game::is_done() {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_is_done__Game_r_bool(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline void Game::shuffle_source(union BIntT0T52T(& a)) {
 rl_m_shuffle_source__Game_BIntT0T52T(this, &a);
}
inline bool Game::can_shuffle_source(union BIntT0T52T(& a)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_can_shuffle_source__Game_BIntT0T52T_r_bool(&_rl__result.payload, this, &a);
 return _rl__result.payload;
}
inline void Game::shuffle_target(union BIntT0T52T(& b)) {
 rl_m_shuffle_target__Game_BIntT0T52T(this, &b);
}
inline bool Game::can_shuffle_target(union BIntT0T52T(& b)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_can_shuffle_target__Game_BIntT0T52T_r_bool(&_rl__result.payload, this, &b);
 return _rl__result.payload;
}
inline void Game::hit() {
 rl_m_hit__Game(this);
}
inline bool Game::can_hit() {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_can_hit__Game_r_bool(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline void Game::stand() {
 rl_m_stand__Game(this);
}
inline bool Game::can_stand() {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_can_stand__Game_r_bool(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline Game::Game() {
 rl_m_init__Game(this);
}
inline Game::~Game() {
 rl_m_drop__Game(this);
}
inline Shuffle::Shuffle() {
 rl_m_init__Shuffle(this);
}
inline Shuffle& Shuffle::operator=(union Shuffle(& other)) {
 rl_m_assign__Shuffle_Shuffle(this, &other);
return *this;
}
inline bool Shuffle::is_done() {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_is_done__Shuffle_r_bool(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline void Shuffle::shuffle_source(union Deck(& deck), union BIntT0T52T(& a)) {
 rl_m_shuffle_source__Shuffle_Deck_BIntT0T52T(this, &deck, &a);
}
inline bool Shuffle::can_shuffle_source(union Deck(& deck), union BIntT0T52T(& a)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_can_shuffle_source__Shuffle_Deck_BIntT0T52T_r_bool(&_rl__result.payload, this, &deck, &a);
 return _rl__result.payload;
}
inline void Shuffle::shuffle_target(union Deck(& deck), union BIntT0T52T(& b)) {
 rl_m_shuffle_target__Shuffle_Deck_BIntT0T52T(this, &deck, &b);
}
inline bool Shuffle::can_shuffle_target(union Deck(& deck), union BIntT0T52T(& b)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_can_shuffle_target__Shuffle_Deck_BIntT0T52T_r_bool(&_rl__result.payload, this, &deck, &b);
 return _rl__result.payload;
}
inline VectorTStringT& VectorTStringT::operator=(union VectorTStringT(& other)) {
 rl_m_assign__VectorTStringT_VectorTStringT(this, &other);
return *this;
}
inline VectorTStringT::~VectorTStringT() {
 rl_m_drop__VectorTStringT(this);
}
inline union String VectorTStringT::pop() {
 union ToReturn { union String payload; ToReturn() {}; ~ToReturn() { payload.~String(); } }	_rl__result;
 rl_m_pop__VectorTStringT_r_String(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline VectorTStringT::VectorTStringT() {
 rl_m_init__VectorTStringT(this);
}
inline void VectorTStringT::append(union String(& value)) {
 rl_m_append__VectorTStringT_String(this, &value);
}
inline union String* VectorTStringT::get(int64_t(& index)) {
 union ToReturn { union String* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_get__VectorTStringT_int64_t_r_StringRef(&_rl__result.payload, this, &index);
 return _rl__result.payload;
}
inline int64_t VectorTStringT::size() {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_size__VectorTStringT_r_int64_t(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline int64_t VectorTdoubleT::size() {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_size__VectorTdoubleT_r_int64_t(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline void VectorTdoubleT::resize(int64_t(& new_size)) {
 rl_m_resize__VectorTdoubleT_int64_t(this, &new_size);
}
inline double VectorTdoubleT::pop() {
 union ToReturn { double payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_pop__VectorTdoubleT_r_double(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline double* VectorTdoubleT::get(int64_t(& index)) {
 union ToReturn { double* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_get__VectorTdoubleT_int64_t_r_doubleRef(&_rl__result.payload, this, &index);
 return _rl__result.payload;
}
inline VectorTdoubleT& VectorTdoubleT::operator=(union VectorTdoubleT(& other)) {
 rl_m_assign__VectorTdoubleT_VectorTdoubleT(this, &other);
return *this;
}
inline VectorTdoubleT::~VectorTdoubleT() {
 rl_m_drop__VectorTdoubleT(this);
}
inline VectorTdoubleT::VectorTdoubleT() {
 rl_m_init__VectorTdoubleT(this);
}
inline void VectorTdoubleT::append(double(& value)) {
 rl_m_append__VectorTdoubleT_double(this, &value);
}
inline void VectorTBIntT0T14TT::append(union BIntT0T14T(& value)) {
 rl_m_append__VectorTBIntT0T14TT_BIntT0T14T(this, &value);
}
inline union BIntT0T14T* VectorTBIntT0T14TT::get(int64_t(& index)) {
 union ToReturn { union BIntT0T14T* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_get__VectorTBIntT0T14TT_int64_t_r_BIntT0T14TRef(&_rl__result.payload, this, &index);
 return _rl__result.payload;
}
inline int64_t VectorTBIntT0T14TT::size() {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_size__VectorTBIntT0T14TT_r_int64_t(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline VectorTBIntT0T14TT::VectorTBIntT0T14TT() {
 rl_m_init__VectorTBIntT0T14TT(this);
}
inline union BIntT0T14T VectorTBIntT0T14TT::pop() {
 union ToReturn { union BIntT0T14T payload; ToReturn() {}; ~ToReturn() { payload.~BIntT0T14T(); } }	_rl__result;
 rl_m_pop__VectorTBIntT0T14TT_r_BIntT0T14T(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline VectorTBIntT0T14TT::~VectorTBIntT0T14TT() {
 rl_m_drop__VectorTBIntT0T14TT(this);
}
inline VectorTBIntT0T14TT& VectorTBIntT0T14TT::operator=(union VectorTBIntT0T14TT(& other)) {
 rl_m_assign__VectorTBIntT0T14TT_VectorTBIntT0T14TT(this, &other);
return *this;
}
inline void VectorTBIntT0T14TT::set(int64_t(& index), union BIntT0T14T(& value)) {
 rl_m_set__VectorTBIntT0T14TT_int64_t_BIntT0T14T(this, &index, &value);
}
inline HiddenTDeckT::HiddenTDeckT() {
 rl_m_init__HiddenTDeckT(this);
}
inline HiddenTDeckT& HiddenTDeckT::operator=(union HiddenTDeckT(& other)) {
 rl_m_assign__HiddenTDeckT_HiddenTDeckT(this, &other);
return *this;
}
inline HiddenTDeckT::~HiddenTDeckT() {
 rl_m_drop__HiddenTDeckT(this);
}
inline HiddenTBoundedVectorTBIntT0T14TT20TT::HiddenTBoundedVectorTBIntT0T14TT20TT() {
 rl_m_init__HiddenTBoundedVectorTBIntT0T14TT20TT(this);
}
inline HiddenTBoundedVectorTBIntT0T14TT20TT::~HiddenTBoundedVectorTBIntT0T14TT20TT() {
 rl_m_drop__HiddenTBoundedVectorTBIntT0T14TT20TT(this);
}
inline HiddenTBoundedVectorTBIntT0T14TT20TT& HiddenTBoundedVectorTBIntT0T14TT20TT::operator=(union HiddenTBoundedVectorTBIntT0T14TT20TT(& other)) {
 rl_m_assign__HiddenTBoundedVectorTBIntT0T14TT20TT_HiddenTBoundedVectorTBIntT0T14TT20TT(this, &other);
return *this;
}
inline GameShuffleSource::GameShuffleSource() {
 rl_m_init__GameShuffleSource(this);
}
inline GameShuffleSource& GameShuffleSource::operator=(union GameShuffleSource(& other)) {
 rl_m_assign__GameShuffleSource_GameShuffleSource(this, &other);
return *this;
}
inline GameShuffleTarget::GameShuffleTarget() {
 rl_m_init__GameShuffleTarget(this);
}
inline GameShuffleTarget& GameShuffleTarget::operator=(union GameShuffleTarget(& other)) {
 rl_m_assign__GameShuffleTarget_GameShuffleTarget(this, &other);
return *this;
}
inline GameHit::GameHit() {
 rl_m_init__GameHit(this);
}
inline GameHit& GameHit::operator=(union GameHit(& other)) {
 rl_m_assign__GameHit_GameHit(this, &other);
return *this;
}
inline GameStand::GameStand() {
 rl_m_init__GameStand(this);
}
inline GameStand& GameStand::operator=(union GameStand(& other)) {
 rl_m_assign__GameStand_GameStand(this, &other);
return *this;
}
inline void AnyGameAction::operator=(union GameStand(& other)) {
 rl_m_assign__AnyGameAction_GameStand(this, &other);
}
inline void AnyGameAction::operator=(union GameShuffleTarget(& other)) {
 rl_m_assign__AnyGameAction_GameShuffleTarget(this, &other);
}
inline AnyGameAction::AnyGameAction() {
 rl_m_init__AnyGameAction(this);
}
inline AnyGameAction& AnyGameAction::operator=(struct AnyGameAction(& other)) {
 rl_m_assign__AnyGameAction_AnyGameAction(this, &other);
return *this;
}
inline void AnyGameAction::operator=(union GameShuffleSource(& other)) {
 rl_m_assign__AnyGameAction_GameShuffleSource(this, &other);
}
inline void AnyGameAction::operator=(union GameHit(& other)) {
 rl_m_assign__AnyGameAction_GameHit(this, &other);
}
inline void VectorTboolT::append(bool(& value)) {
 rl_m_append__VectorTboolT_bool(this, &value);
}
inline bool* VectorTboolT::get(int64_t(& index)) {
 union ToReturn { bool* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_get__VectorTboolT_int64_t_r_boolRef(&_rl__result.payload, this, &index);
 return _rl__result.payload;
}
inline VectorTboolT& VectorTboolT::operator=(union VectorTboolT(& other)) {
 rl_m_assign__VectorTboolT_VectorTboolT(this, &other);
return *this;
}
inline VectorTboolT::~VectorTboolT() {
 rl_m_drop__VectorTboolT(this);
}
inline VectorTboolT::VectorTboolT() {
 rl_m_init__VectorTboolT(this);
}
inline int64_t BoundedVectorTBIntT0T14TT20T::size() {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_size__BoundedVectorTBIntT0T14TT20T_r_int64_t(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline union BIntT0T14T* BoundedVectorTBIntT0T14TT20T::get(int64_t(& index)) {
 union ToReturn { union BIntT0T14T* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_get__BoundedVectorTBIntT0T14TT20T_int64_t_r_BIntT0T14TRef(&_rl__result.payload, this, &index);
 return _rl__result.payload;
}
inline void BoundedVectorTBIntT0T14TT20T::append(union BIntT0T14T(& value)) {
 rl_m_append__BoundedVectorTBIntT0T14TT20T_BIntT0T14T(this, &value);
}
inline BoundedVectorTBIntT0T14TT20T::~BoundedVectorTBIntT0T14TT20T() {
 rl_m_drop__BoundedVectorTBIntT0T14TT20T(this);
}
inline BoundedVectorTBIntT0T14TT20T::BoundedVectorTBIntT0T14TT20T() {
 rl_m_init__BoundedVectorTBIntT0T14TT20T(this);
}
inline BoundedVectorTBIntT0T14TT20T& BoundedVectorTBIntT0T14TT20T::operator=(union BoundedVectorTBIntT0T14TT20T(& other)) {
 rl_m_assign__BoundedVectorTBIntT0T14TT20T_BoundedVectorTBIntT0T14TT20T(this, &other);
return *this;
}
inline int64_t String::size() {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_size__String_r_int64_t(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline bool String::not_equal(char*(& other)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_not_equal__String_strlit_r_bool(&_rl__result.payload, this, &other);
 return _rl__result.payload;
}
inline bool String::not_equal(union String(& other)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_not_equal__String_String_r_bool(&_rl__result.payload, this, &other);
 return _rl__result.payload;
}
inline void String::drop_back(int64_t(& quantity)) {
 rl_m_drop_back__String_int64_t(this, &quantity);
}
inline String::String() {
 rl_m_init__String(this);
}
inline void String::reverse() {
 rl_m_reverse__String(this);
}
inline bool String::substring_matches(char*(& lit), int64_t(& pos)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_substring_matches__String_strlit_int64_t_r_bool(&_rl__result.payload, this, &lit, &pos);
 return _rl__result.payload;
}
inline void String::append(int8_t(& b)) {
 rl_m_append__String_int8_t(this, &b);
}
inline void String::append_quoted(union String(& str)) {
 rl_m_append_quoted__String_String(this, &str);
}
inline union String String::to_indented_lines() {
 union ToReturn { union String payload; ToReturn() {}; ~ToReturn() { payload.~String(); } }	_rl__result;
 rl_m_to_indented_lines__String_r_String(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline String& String::operator=(union String(& other)) {
 rl_m_assign__String_String(this, &other);
return *this;
}
inline int64_t String::count(int8_t(& b)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_count__String_int8_t_r_int64_t(&_rl__result.payload, this, &b);
 return _rl__result.payload;
}
inline void String::append(char*(& str)) {
 rl_m_append__String_strlit(this, &str);
}
inline union String String::add(union String(& other)) {
 union ToReturn { union String payload; ToReturn() {}; ~ToReturn() { payload.~String(); } }	_rl__result;
 rl_m_add__String_String_r_String(&_rl__result.payload, this, &other);
 return _rl__result.payload;
}
inline int8_t* String::get(int64_t(& index)) {
 union ToReturn { int8_t* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_get__String_int64_t_r_int8_tRef(&_rl__result.payload, this, &index);
 return _rl__result.payload;
}
inline int8_t* String::back() {
 union ToReturn { int8_t* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_back__String_r_int8_tRef(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline void String::append(union String(& str)) {
 rl_m_append__String_String(this, &str);
}
inline bool String::operator==(char*(& other)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_equal__String_strlit_r_bool(&_rl__result.payload, this, &other);
 return _rl__result.payload;
}
inline String::~String() {
 rl_m_drop__String(this);
}
inline bool String::operator==(union String(& other)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_equal__String_String_r_bool(&_rl__result.payload, this, &other);
 return _rl__result.payload;
}
inline Deck::~Deck() {
 rl_m_drop__Deck(this);
}
inline Deck& Deck::operator=(union Deck(& other)) {
 rl_m_assign__Deck_Deck(this, &other);
return *this;
}
inline void Deck::switch_cards(int64_t(& a), int64_t(& b)) {
 rl_m_switch_cards__Deck_int64_t_int64_t(this, &a, &b);
}
inline Deck::Deck() {
 rl_m_init__Deck(this);
}
inline BIntT0T14T& BIntT0T14T::operator=(union BIntT0T14T(& other)) {
 rl_m_assign__BIntT0T14T_BIntT0T14T(this, &other);
return *this;
}
inline bool BIntT0T14T::less_equal(int64_t(& other)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_less_equal__BIntT0T14T_int64_t_r_bool(&_rl__result.payload, this, &other);
 return _rl__result.payload;
}
inline bool BIntT0T14T::operator==(int64_t(& other)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_equal__BIntT0T14T_int64_t_r_bool(&_rl__result.payload, this, &other);
 return _rl__result.payload;
}
inline BIntT0T14T::BIntT0T14T() {
 rl_m_init__BIntT0T14T(this);
}
inline BIntT0T52T::BIntT0T52T() {
 rl_m_init__BIntT0T52T(this);
}
inline BIntT0T52T& BIntT0T52T::operator=(union BIntT0T52T(& other)) {
 rl_m_assign__BIntT0T52T_BIntT0T52T(this, &other);
return *this;
}
inline int8_t* VectorTint8_tT::get(int64_t(& index)) {
 union ToReturn { int8_t* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_get__VectorTint8_tT_int64_t_r_int8_tRef(&_rl__result.payload, this, &index);
 return _rl__result.payload;
}
inline void VectorTint8_tT::drop_back(int64_t(& quantity)) {
 rl_m_drop_back__VectorTint8_tT_int64_t(this, &quantity);
}
inline VectorTint8_tT::VectorTint8_tT() {
 rl_m_init__VectorTint8_tT(this);
}
inline void VectorTint8_tT::append(int8_t(& value)) {
 rl_m_append__VectorTint8_tT_int8_t(this, &value);
}
inline int8_t* VectorTint8_tT::back() {
 union ToReturn { int8_t* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_back__VectorTint8_tT_r_int8_tRef(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline VectorTint8_tT& VectorTint8_tT::operator=(union VectorTint8_tT(& other)) {
 rl_m_assign__VectorTint8_tT_VectorTint8_tT(this, &other);
return *this;
}
inline VectorTint8_tT::~VectorTint8_tT() {
 rl_m_drop__VectorTint8_tT(this);
}
inline int64_t VectorTint8_tT::size() {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_size__VectorTint8_tT_r_int64_t(&_rl__result.payload, this);
 return _rl__result.payload;
}
inline int8_t VectorTint8_tT::pop() {
 union ToReturn { int8_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_m_pop__VectorTint8_tT_r_int8_t(&_rl__result.payload, this);
 return _rl__result.payload;
}
#endif
typedef union BIntT0T14T Card;
typedef union BIntT0T52T CardIndex;
typedef struct AnyGameAction AnyGameAction;
#ifdef __cplusplus
inline void init(char*(& self)) {
 rl_m_init__strlit(&self);
}
inline void assign(char*(& self), char*(& other)) {
 rl_m_assign__strlit_strlit(&self, &other);
}
inline void append_to_string(union HiddenTDeckT(& to_add), union String(& output)) {
 rl_append_to_string__HiddenTDeckT_String(&to_add, &output);
}
inline void print(union String(& to_print)) {
 rl_print__String(&to_print);
}
inline void append_to_vector(int64_t(& to_add), union VectorTint8_tT(& output)) {
 rl_append_to_vector__int64_t_VectorTint8_tT(&to_add, &output);
}
inline void append_to_vector(double(& to_add), union VectorTint8_tT(& output)) {
 rl_append_to_vector__double_VectorTint8_tT(&to_add, &output);
}
inline void append_to_vector(bool(& to_add), union VectorTint8_tT(& output)) {
 rl_append_to_vector__bool_VectorTint8_tT(&to_add, &output);
}
inline void append_to_vector(int8_t(& to_add), union VectorTint8_tT(& output)) {
 rl_append_to_vector__int8_t_VectorTint8_tT(&to_add, &output);
}
inline bool parse_from_vector(int64_t(& result), union VectorTint8_tT(& input), int64_t(& index)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_parse_from_vector__int64_t_VectorTint8_tT_int64_t_r_bool(&_rl__result.payload , &result, &input, &index);
 return _rl__result.payload;
}
inline bool parse_from_vector(double(& result), union VectorTint8_tT(& input), int64_t(& index)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_parse_from_vector__double_VectorTint8_tT_int64_t_r_bool(&_rl__result.payload , &result, &input, &index);
 return _rl__result.payload;
}
inline bool parse_from_vector(bool(& result), union VectorTint8_tT(& input), int64_t(& index)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_parse_from_vector__bool_VectorTint8_tT_int64_t_r_bool(&_rl__result.payload , &result, &input, &index);
 return _rl__result.payload;
}
inline bool parse_from_vector(int8_t(& result), union VectorTint8_tT(& input), int64_t(& index)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_parse_from_vector__int8_t_VectorTint8_tT_int64_t_r_bool(&_rl__result.payload , &result, &input, &index);
 return _rl__result.payload;
}
inline bool from_byte_vector(int8_t(& result), union VectorTint8_tT(& input), int64_t(& read_bytes)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_from_byte_vector__int8_t_VectorTint8_tT_int64_t_r_bool(&_rl__result.payload , &result, &input, &read_bytes);
 return _rl__result.payload;
}
inline union String s(char*(& literal)) {
 union ToReturn { union String payload; ToReturn() {}; ~ToReturn() { payload.~String(); } }	_rl__result;
 rl_s__strlit_r_String(&_rl__result.payload , &literal);
 return _rl__result.payload;
}
inline void append_to_string(char*(& x), union String(& output)) {
 rl_append_to_string__strlit_String(&x, &output);
}
inline void append_to_string(union String(& x), union String(& output)) {
 rl_append_to_string__String_String(&x, &output);
}
inline void append_to_string(bool(& x), union String(& output)) {
 rl_append_to_string__bool_String(&x, &output);
}
inline void append_to_string(union VectorTBIntT0T14TT(& to_add), union String(& output)) {
 rl_append_to_string__VectorTBIntT0T14TT_String(&to_add, &output);
}
inline void append_to_string(union BoundedVectorTBIntT0T14TT20T(& to_add), union String(& output)) {
 rl_append_to_string__BoundedVectorTBIntT0T14TT20T_String(&to_add, &output);
}
inline void to_string(union Deck(& to_stringyfi), union String(& output)) {
 rl_to_string__Deck_String(&to_stringyfi, &output);
}
inline union String to_string(union HiddenTDeckT(& to_stringyfi)) {
 union ToReturn { union String payload; ToReturn() {}; ~ToReturn() { payload.~String(); } }	_rl__result;
 rl_to_string__HiddenTDeckT_r_String(&_rl__result.payload , &to_stringyfi);
 return _rl__result.payload;
}
inline union String to_string(union BoundedVectorTBIntT0T14TT20T(& to_stringyfi)) {
 union ToReturn { union String payload; ToReturn() {}; ~ToReturn() { payload.~String(); } }	_rl__result;
 rl_to_string__BoundedVectorTBIntT0T14TT20T_r_String(&_rl__result.payload , &to_stringyfi);
 return _rl__result.payload;
}
inline bool is_space(int8_t(& b)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_is_space__int8_t_r_bool(&_rl__result.payload , &b);
 return _rl__result.payload;
}
inline bool is_open_paren(int8_t(& b)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_is_open_paren__int8_t_r_bool(&_rl__result.payload , &b);
 return _rl__result.payload;
}
inline bool is_close_paren(int8_t(& b)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_is_close_paren__int8_t_r_bool(&_rl__result.payload , &b);
 return _rl__result.payload;
}
inline int64_t length(char*(& literal)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_length__strlit_r_int64_t(&_rl__result.payload , &literal);
 return _rl__result.payload;
}
inline bool parse_string(union String(& result), union String(& buffer), int64_t(& index)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_parse_string__String_String_int64_t_r_bool(&_rl__result.payload , &result, &buffer, &index);
 return _rl__result.payload;
}
inline bool parse_string(bool(& result), union String(& buffer), int64_t(& index)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_parse_string__bool_String_int64_t_r_bool(&_rl__result.payload , &result, &buffer, &index);
 return _rl__result.payload;
}
inline void append_to_string(union BIntT0T14T(& to_add), union String(& output)) {
 rl_append_to_string__BIntT0T14T_String(&to_add, &output);
}
inline int64_t max(int64_t(& a), int64_t(& b)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_max__int64_t_int64_t_r_int64_t(&_rl__result.payload , &a, &b);
 return _rl__result.payload;
}
inline int64_t min(int64_t(& a), int64_t(& b)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_min__int64_t_int64_t_r_int64_t(&_rl__result.payload , &a, &b);
 return _rl__result.payload;
}
inline int64_t abs(int64_t(& a)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_abs__int64_t_r_int64_t(&_rl__result.payload , &a);
 return _rl__result.payload;
}
inline bool near(double(& value), double(& target), double(& distance)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_near__double_double_double_r_bool(&_rl__result.payload , &value, &target, &distance);
 return _rl__result.payload;
}
inline bool custom_equal(int64_t(& lhs), int64_t(& rhs)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_custom_equal__int64_t_int64_t_r_bool(&_rl__result.payload , &lhs, &rhs);
 return _rl__result.payload;
}
inline bool custom_equal(bool(& lhs), bool(& rhs)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_custom_equal__bool_bool_r_bool(&_rl__result.payload , &lhs, &rhs);
 return _rl__result.payload;
}
inline bool custom_equal(int8_t(& lhs), int8_t(& rhs)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_custom_equal__int8_t_int8_t_r_bool(&_rl__result.payload , &lhs, &rhs);
 return _rl__result.payload;
}
inline bool custom_equal(double(& lhs), double(& rhs)) {
 union ToReturn { bool payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_custom_equal__double_double_r_bool(&_rl__result.payload , &lhs, &rhs);
 return _rl__result.payload;
}
inline void enumerate(bool(& b), union VectorTboolT(& output)) {
 rl_enumerate__bool_VectorTboolT(&b, &output);
}
inline void enumeration_error(int64_t(& x), union String(& out), union VectorTStringT(& context)) {
 rl_enumeration_error__int64_t_String_VectorTStringT(&x, &out, &context);
}
inline void enumeration_error(double(& x), union String(& out), union VectorTStringT(& context)) {
 rl_enumeration_error__double_String_VectorTStringT(&x, &out, &context);
}
inline void write_in_observation_tensor(int64_t(& value), int64_t(& min), int64_t(& max), union VectorTdoubleT(& output), int64_t(& index)) {
 rl_write_in_observation_tensor__int64_t_int64_t_int64_t_VectorTdoubleT_int64_t(&value, &min, &max, &output, &index);
}
inline void write_in_observation_tensor(int64_t(& obj), int64_t(& observer_id), union VectorTdoubleT(& output), int64_t(& index)) {
 rl_write_in_observation_tensor__int64_t_int64_t_VectorTdoubleT_int64_t(&obj, &observer_id, &output, &index);
}
inline int64_t size_as_observation_tensor(int64_t(& obj)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_size_as_observation_tensor__int64_t_r_int64_t(&_rl__result.payload , &obj);
 return _rl__result.payload;
}
inline void write_in_observation_tensor(double(& obj), int64_t(& observer_id), union VectorTdoubleT(& output), int64_t(& index)) {
 rl_write_in_observation_tensor__double_int64_t_VectorTdoubleT_int64_t(&obj, &observer_id, &output, &index);
}
inline bool can_write_in_observation_tensor(double(& obj), int64_t(& observer_id), union VectorTdoubleT(& output), int64_t(& index)) {
bool toReturn;
 rl_can_write_in_observation_tensor__double_int64_t_VectorTdoubleT_int64_t_r_bool(&toReturn , &obj, &observer_id, &output, &index);
 return toReturn;
}
inline int64_t size_as_observation_tensor(double(& obj)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_size_as_observation_tensor__double_r_int64_t(&_rl__result.payload , &obj);
 return _rl__result.payload;
}
inline bool can_size_as_observation_tensor(double(& obj)) {
bool toReturn;
 rl_can_size_as_observation_tensor__double_r_bool(&toReturn , &obj);
 return toReturn;
}
inline void write_in_observation_tensor(bool(& obj), int64_t(& observer_id), union VectorTdoubleT(& output), int64_t(& index)) {
 rl_write_in_observation_tensor__bool_int64_t_VectorTdoubleT_int64_t(&obj, &observer_id, &output, &index);
}
inline int64_t size_as_observation_tensor(bool(& obj)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_size_as_observation_tensor__bool_r_int64_t(&_rl__result.payload , &obj);
 return _rl__result.payload;
}
inline void write_in_observation_tensor(int8_t(& obj), int64_t(& observer_id), union VectorTdoubleT(& output), int64_t(& index)) {
 rl_write_in_observation_tensor__int8_t_int64_t_VectorTdoubleT_int64_t(&obj, &observer_id, &output, &index);
}
inline int64_t size_as_observation_tensor(int8_t(& obj)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_size_as_observation_tensor__int8_t_r_int64_t(&_rl__result.payload , &obj);
 return _rl__result.payload;
}
inline void write_tensor_warning_context(union String(& out), union VectorTStringT(& context)) {
 rl_write_tensor_warning_context__String_VectorTStringT(&out, &context);
}
inline void tensorable_warning(int64_t(& x), union String(& out), union VectorTStringT(& context)) {
 rl_tensorable_warning__int64_t_String_VectorTStringT(&x, &out, &context);
}
inline void tensorable_warning(double(& x), union String(& out), union VectorTStringT(& context)) {
 rl_tensorable_warning__double_String_VectorTStringT(&x, &out, &context);
}
inline void draw(union Deck(& deck), union BoundedVectorTBIntT0T14TT20T(& hand)) {
 rl_draw__Deck_BoundedVectorTBIntT0T14TT20T(&deck, &hand);
}
inline void deal(union Deck(& deck), union BoundedVectorTBIntT0T14TT20T(& hand)) {
 rl_deal__Deck_BoundedVectorTBIntT0T14TT20T(&deck, &hand);
}
inline int64_t calculate_points(union BoundedVectorTBIntT0T14TT20T(& hand)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_calculate_points__BoundedVectorTBIntT0T14TT20T_r_int64_t(&_rl__result.payload , &hand);
 return _rl__result.payload;
}
inline void apply(union GameShuffleSource(& self), union Game(& frame)) {
 rl_apply__GameShuffleSource_Game(&self, &frame);
}
inline bool can_apply(union GameShuffleSource(& self), union Game(& frame)) {
bool toReturn;
 rl_can_apply__GameShuffleSource_Game_r_bool(&toReturn , &self, &frame);
 return toReturn;
}
inline char* get_type_name(union GameShuffleSource(& self)) {
 union ToReturn { char* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_get_type_name__GameShuffleSource_r_strlit(&_rl__result.payload , &self);
 return _rl__result.payload;
}
inline void apply(union GameShuffleTarget(& self), union Game(& frame)) {
 rl_apply__GameShuffleTarget_Game(&self, &frame);
}
inline bool can_apply(union GameShuffleTarget(& self), union Game(& frame)) {
bool toReturn;
 rl_can_apply__GameShuffleTarget_Game_r_bool(&toReturn , &self, &frame);
 return toReturn;
}
inline char* get_type_name(union GameShuffleTarget(& self)) {
 union ToReturn { char* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_get_type_name__GameShuffleTarget_r_strlit(&_rl__result.payload , &self);
 return _rl__result.payload;
}
inline void apply(union GameHit(& self), union Game(& frame)) {
 rl_apply__GameHit_Game(&self, &frame);
}
inline bool can_apply(union GameHit(& self), union Game(& frame)) {
bool toReturn;
 rl_can_apply__GameHit_Game_r_bool(&toReturn , &self, &frame);
 return toReturn;
}
inline char* get_type_name(union GameHit(& self)) {
 union ToReturn { char* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_get_type_name__GameHit_r_strlit(&_rl__result.payload , &self);
 return _rl__result.payload;
}
inline void apply(union GameStand(& self), union Game(& frame)) {
 rl_apply__GameStand_Game(&self, &frame);
}
inline bool can_apply(union GameStand(& self), union Game(& frame)) {
bool toReturn;
 rl_can_apply__GameStand_Game_r_bool(&toReturn , &self, &frame);
 return toReturn;
}
inline char* get_type_name(union GameStand(& self)) {
 union ToReturn { char* payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_get_type_name__GameStand_r_strlit(&_rl__result.payload , &self);
 return _rl__result.payload;
}
inline void apply(struct AnyGameAction(& self), union Game(& frame)) {
 rl_apply__AnyGameAction_Game(&self, &frame);
}
inline bool can_apply(struct AnyGameAction(& self), union Game(& frame)) {
bool toReturn;
 rl_can_apply__AnyGameAction_Game_r_bool(&toReturn , &self, &frame);
 return toReturn;
}
inline int64_t get_current_player(union Game(& g)) {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_get_current_player__Game_r_int64_t(&_rl__result.payload , &g);
 return _rl__result.payload;
}
inline int64_t get_num_players() {
 union ToReturn { int64_t payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_get_num_players__r_int64_t(&_rl__result.payload );
 return _rl__result.payload;
}
inline double score(union Game(& g), int64_t(& player_id)) {
 union ToReturn { double payload; ToReturn() {}; ~ToReturn() { } }	_rl__result;
 rl_score__Game_int64_t_r_double(&_rl__result.payload , &g, &player_id);
 return _rl__result.payload;
}
inline void pretty_print(union Game(& g)) {
 rl_pretty_print__Game(&g);
}
inline union Game play() {
 union ToReturn { union Game payload; ToReturn() {}; ~ToReturn() { payload.~Game(); } }	_rl__result;
 rl_play__r_Game(&_rl__result.payload );
 return _rl__result.payload;
}
inline union Shuffle shuffle(union Deck(& deck)) {
 union ToReturn { union Shuffle payload; ToReturn() {}; ~ToReturn() { payload.~Shuffle(); } }	_rl__result;
 rl_shuffle__Deck_r_Shuffle(&_rl__result.payload , &deck);
 return _rl__result.payload;
}
#endif
#undef RLC_GET_TYPE_DEFS
#endif

