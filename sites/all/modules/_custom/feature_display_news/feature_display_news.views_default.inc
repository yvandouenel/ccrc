<?php
/**
 * @file
 * feature_display_news.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_display_news_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'actualites_accueil';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Actualités accueil';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Actualités';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Contenu: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
  $handler->display->display_options['fields']['field_image_news']['id'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['table'] = 'field_data_field_image_news';
  $handler->display->display_options['fields']['field_image_news']['field'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['label'] = '';
  $handler->display->display_options['fields']['field_image_news']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_news']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_news']['settings'] = array(
    'image_style' => 'actu_home',
    'image_link' => 'content',
  );
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Champ: Contenu: Résumé */
  $handler->display->display_options['fields']['field_summary_news']['id'] = 'field_summary_news';
  $handler->display->display_options['fields']['field_summary_news']['table'] = 'field_data_field_summary_news';
  $handler->display->display_options['fields']['field_summary_news']['field'] = 'field_summary_news';
  $handler->display->display_options['fields']['field_summary_news']['label'] = '';
  $handler->display->display_options['fields']['field_summary_news']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_summary_news']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_summary_news']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_summary_news']['element_label_colon'] = FALSE;
  /* Sort criterion: Contenu: Ordre d&#039;afichage (field_order_news) */
  $handler->display->display_options['sorts']['field_order_news_value']['id'] = 'field_order_news_value';
  $handler->display->display_options['sorts']['field_order_news_value']['table'] = 'field_data_field_order_news';
  $handler->display->display_options['sorts']['field_order_news_value']['field'] = 'field_order_news_value';
  /* Sort criterion: Contenu: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Contenu: Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenu: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'actualites' => 'actualites',
  );
  /* Filter criterion: Contenu: Mise en avant (field_home_news) */
  $handler->display->display_options['filters']['field_home_news_value']['id'] = 'field_home_news_value';
  $handler->display->display_options['filters']['field_home_news_value']['table'] = 'field_data_field_home_news';
  $handler->display->display_options['filters']['field_home_news_value']['field'] = 'field_home_news_value';
  $handler->display->display_options['filters']['field_home_news_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block actu accueil */
  $handler = $view->new_display('block', 'Block actu accueil', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Page Actualités */
  $handler = $view->new_display('page', 'Page Actualités', 'page_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'page-actu-all';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Champ: Contenu: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Champ: Contenu: Image */
  $handler->display->display_options['fields']['field_image_news']['id'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['table'] = 'field_data_field_image_news';
  $handler->display->display_options['fields']['field_image_news']['field'] = 'field_image_news';
  $handler->display->display_options['fields']['field_image_news']['label'] = '';
  $handler->display->display_options['fields']['field_image_news']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_news']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_news']['settings'] = array(
    'image_style' => 'actu_home',
    'image_link' => 'content',
  );
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h3 class="title-actu-in-page"><a href="/node/[nid]">[title]</a></h3>';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Champ: Contenu: Résumé */
  $handler->display->display_options['fields']['field_summary_news']['id'] = 'field_summary_news';
  $handler->display->display_options['fields']['field_summary_news']['table'] = 'field_data_field_summary_news';
  $handler->display->display_options['fields']['field_summary_news']['field'] = 'field_summary_news';
  $handler->display->display_options['fields']['field_summary_news']['label'] = '';
  $handler->display->display_options['fields']['field_summary_news']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_summary_news']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_summary_news']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_summary_news']['element_label_colon'] = FALSE;
  /* Champ: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="clear"></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Contenu: Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Contenu: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'actualites' => 'actualites',
  );
  $handler->display->display_options['path'] = 'actualites';
  $translatables['actualites_accueil'] = array(
    t('Master'),
    t('Actualités'),
    t('more'),
    t('Apply'),
    t('Réinitialiser'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block actu accueil'),
    t('Page Actualités'),
    t('<h3 class="title-actu-in-page"><a href="/node/[nid]">[title]</a></h3>'),
    t('<div class="clear"></div>'),
  );
  $export['actualites_accueil'] = $view;

  return $export;
}
