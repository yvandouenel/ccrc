<?php
/**
 * @file
 * feature_display_news.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function feature_display_news_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|actualites|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'actualites';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_image_news',
        2 => 'field_dates_news',
        3 => 'field_thematic_news',
        4 => 'field_summary_news',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_image_news' => 'ds_content',
      'field_dates_news' => 'ds_content',
      'field_thematic_news' => 'ds_content',
      'field_summary_news' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => FALSE,
  );
  $export['node|actualites|default'] = $ds_layout;

  return $export;
}
