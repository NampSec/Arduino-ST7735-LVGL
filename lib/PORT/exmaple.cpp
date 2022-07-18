#include "../LVGL/lvgl.h"


static void btn_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        static uint8_t cnt = 0;
        cnt++;

        /*Get the first child of the button which is the label and change its text*/
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", cnt);
    }
}

/**
 * Create a button with a label and react on click event.
 */
void lv_example_get_started_1()
{
    LV_IMG_DECLARE(_shuaige_100x120);
    lv_obj_t * imgs = lv_img_create(lv_scr_act());
	lv_obj_set_pos(imgs, 14, 20);
	lv_obj_set_size(imgs, 100, 120);
    lv_img_set_src(imgs, &_shuaige_100x120);
    // lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    // lv_obj_set_pos(btn, 10, 10);                            /*Set its position*/
    // lv_obj_set_size(btn, 30, 40);                          /*Set its size*/
    // lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_ALL, NULL);           /*Assign a callback to the button*/

    // lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    // lv_label_set_text(label, "LJBJJZ");                     /*Set the labels text*/
    // lv_obj_center(label);
}
// }
// void setup_scr_screen(lv_ui *ui){

// 	//Write codes screen
// 	ui->screen = lv_obj_create(NULL);

// 	//Write style state: LV_STATE_DEFAULT for style_screen_main_main_default
// 	static lv_style_t style_screen_main_main_default;
// 	if (style_screen_main_main_default.prop_cnt > 1)
// 		lv_style_reset(&style_screen_main_main_default);
// 	else
// 		lv_style_init(&style_screen_main_main_default);
// 	lv_style_set_bg_color(&style_screen_main_main_default, lv_color_make(0xff, 0xff, 0xff));
// 	lv_style_set_bg_opa(&style_screen_main_main_default, 255);
// 	lv_obj_add_style(ui->screen, &style_screen_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

// 	//Write codes screen_img_1
// 	ui->screen_img_1 = lv_img_create(ui->screen);
// 	lv_obj_set_pos(ui->screen_img_1, 14, 20);
// 	lv_obj_set_size(ui->screen_img_1, 100, 120);

// 	//Write style state: LV_STATE_DEFAULT for style_screen_img_1_main_main_default
// 	static lv_style_t style_screen_img_1_main_main_default;
// 	if (style_screen_img_1_main_main_default.prop_cnt > 1)
//     {
// 		lv_style_reset(&style_screen_img_1_main_main_default);
// 	}
//     else
//     {
// 		lv_style_init(&style_screen_img_1_main_main_default);
// 	}
//     lv_style_set_img_recolor(&style_screen_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
// 	lv_style_set_img_recolor_opa(&style_screen_img_1_main_main_default, 0);
// 	lv_style_set_img_opa(&style_screen_img_1_main_main_default, 255);
// 	lv_obj_add_style(ui->screen_img_1, &style_screen_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
// 	lv_obj_add_flag(ui->screen_img_1, LV_OBJ_FLAG_CLICKABLE);
// 	lv_img_set_src(ui->screen_img_1,&_shuaige_100x120);
// 	lv_img_set_pivot(ui->screen_img_1, 0,0);
// 	lv_img_set_angle(ui->screen_img_1, 0);
// }