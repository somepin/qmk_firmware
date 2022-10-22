/* Macros */


bool is_shift_lock_active = false; 
bool   is_char_jump_active = false; 
uint16_t char_jump_timer = 0; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOCK_SHIFT:
      if (record->event.pressed) {
        if (!is_shift_lock_active) {
          is_shift_lock_active = true;
          register_code(KC_LSFT);
        }
        else{
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        }         
      } 
      break;

    case COPY:
      if (record->event.pressed) {
             SEND_STRING(SS_LCTL("c"));
        if (is_shift_lock_active) {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        }
      } 
      break;
    case CUT:
      if (record->event.pressed) {
             SEND_STRING(SS_LCTL("x"));
         if (is_shift_lock_active) {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        }
      } 
      break;
      
   case PASTE:
      if (record->event.pressed) {
             SEND_STRING(SS_LCTL("v"));
         if (is_shift_lock_active) {
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
        }
      } 
      break;
      
      case MATHFRAC:
      if (record->event.pressed) {
	SEND_STRING(SS_TAP(X_BSLS)"frac ");
      } 
      break;

      
      case MATHENVCENTER:
      if (record->event.pressed) {
	 register_code(KC_LSFT);	
         SEND_STRING(SS_LCTL("m"));
	 unregister_code(KC_LSFT);
      } 
      break;
            
    case DOMATH:
        if (record->event.pressed) {
             SEND_STRING(SS_LALT("emsa")); 
        } else {
        }
        break;
        
     case CUTWORD:
      if (record->event.pressed) {
		unregister_code(KC_LSFT);
		register_code(KC_LCTRL);
        SEND_STRING(SS_TAP(X_RIGHT));
        SEND_STRING(SS_TAP(X_LEFT));
		register_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_RIGHT));
		unregister_code(KC_LSFT);
		unregister_code(KC_LCTRL);		
        SEND_STRING(SS_LCTL("x"));
        is_shift_lock_active = false;
      } 
      break;      
       
     case COPYWORD:
      if (record->event.pressed) {
		unregister_code(KC_LSFT);
		register_code(KC_LCTRL);
        SEND_STRING(SS_TAP(X_RIGHT));
        SEND_STRING(SS_TAP(X_LEFT));
		register_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_RIGHT));
		unregister_code(KC_LSFT);
		unregister_code(KC_LCTRL);		
        SEND_STRING(SS_LCTL("c"));
        is_shift_lock_active = false;
      } 
      break;       

     case CUTLINE:
      if (record->event.pressed) {
		unregister_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_HOME));
		register_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_END));
		unregister_code(KC_LSFT);		
        SEND_STRING(SS_LCTL("x"));
        is_shift_lock_active = false;
      } 
      break;       

     case COPYLINE:
      if (record->event.pressed) {
		unregister_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_HOME));
		register_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_TAP(X_END));
		unregister_code(KC_LSFT);		
        SEND_STRING(SS_LCTL("c"));
        is_shift_lock_active = false;
      } 
      break;       

    case LINEDOWN:
      if (record->event.pressed) {
		unregister_code(KC_LSFT);
		SEND_STRING(SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME)SS_TAP(X_HOME));  
        register_code(KC_LSFT);
        SEND_STRING(SS_TAP(X_END));	
        unregister_code(KC_LSFT);
        SEND_STRING(SS_LCTL("c"));
        SEND_STRING(SS_TAP(X_END)SS_TAP(X_ENT));
        SEND_STRING(SS_LCTL("v"));        
        is_shift_lock_active = false;
      } 
      break;
      
    case COPYDOWN:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL("c"));
          is_shift_lock_active = false;
          unregister_code(KC_LSFT);
          SEND_STRING(SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END)SS_TAP(X_END));	  
          SEND_STRING(SS_TAP(X_ENT));	        
	  SEND_STRING(SS_LCTL("M"));
          SEND_STRING(SS_LCTL("v"));	  
      } 
      break;        

     case JUMP_WORD:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_LEFT)SS_UP(X_LSFT)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_F)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_V)SS_UP(X_LCTL)SS_TAP(X_ENT)SS_TAP(X_ESC)SS_TAP(X_LEFT));
      } 
      break;        

     case JUMP_CHAR:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LSFT)SS_TAP(X_LEFT)SS_UP(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_F)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_V)SS_UP(X_LCTL)SS_TAP(X_ENT)SS_TAP(X_ESC)SS_TAP(X_LEFT));
      } 
      break;        


     case JUMP_AGAIN:
      if (record->event.pressed) {

          SEND_STRING(SS_TAP(X_RIGHT)SS_DOWN(X_LCTL)SS_TAP(X_F)SS_TAP(X_V)SS_UP(X_LCTL)SS_TAP(X_ENT)SS_TAP(X_ESC)SS_TAP(X_LEFT));

	
      } 
      break;        	

  case POP:
      if (record->event.pressed) {

          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_1)SS_UP(X_LGUI)SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_TAP(X_DEL)SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT)SS_DOWN(X_LCTL));
          wait_ms(200);	  
          SEND_STRING(SS_TAP(X_V)SS_UP(X_LCTL));

	
      } 
      break;        	


  case PUSH:
      if (record->event.pressed) {

          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_C)SS_UP(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_1)SS_UP(X_LGUI));
          wait_ms(200);
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_V)SS_UP(X_LCTL)SS_TAP(X_ENT)SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT));

	
      } 
      break;        	

  case PUSH_KILL:
      if (record->event.pressed) {

          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_X)SS_UP(X_LCTL)SS_DOWN(X_LGUI)SS_TAP(X_1)SS_UP(X_LGUI));
          wait_ms(200);
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL)SS_DOWN(X_LCTL)SS_TAP(X_V)SS_UP(X_LCTL)SS_TAP(X_ENT)SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT));

	
      } 
      break;        	


  case DUP:
      if (record->event.pressed) {

          SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_1)SS_UP(X_LGUI));
          wait_ms(200);
          SEND_STRING(SS_DOWN(X_LCTL)SS_TAP(X_HOME)SS_UP(X_LCTL)SS_DOWN(X_LSFT)SS_TAP(X_END)SS_UP(X_LSFT)SS_DOWN(X_LCTL)SS_TAP(X_C)SS_UP(X_LCTL)SS_TAP(X_LEFT)SS_TAP(X_ENT)SS_TAP(X_UP)SS_DOWN(X_LCTL)SS_TAP(X_V)SS_UP(X_LCTL)SS_DOWN(X_LALT)SS_TAP(X_TAB)SS_UP(X_LALT));
	
      } 
      break;        	



  }
  return true;
};

void matrix_scan_user(void) { // The very important timer.
  if (is_char_jump_active) {
    if (timer_elapsed(char_jump_timer) > 1000) {
      is_char_jump_active = false;
    }
  }
}
