<?php
/**
 * @file
 * intranet.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function intranet_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'informations_internes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Informations internes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Informations internes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'simple_access';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Envoyer';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Résultats par page';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« premier';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ précédent';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'suivant ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'dernier »';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = '<h3>Aucun résultat ne correspond à votre requête</h3>
Veuillez la modifier les critères à la gauche de ce message';
  /* Champ: Contenu: Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Champ: Contenu: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Résumé';
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  /* Champ: Contenu: Fichiers joints */
  $handler->display->display_options['fields']['field_interne_fichiers']['id'] = 'field_interne_fichiers';
  $handler->display->display_options['fields']['field_interne_fichiers']['table'] = 'field_data_field_interne_fichiers';
  $handler->display->display_options['fields']['field_interne_fichiers']['field'] = 'field_interne_fichiers';
  $handler->display->display_options['fields']['field_interne_fichiers']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_interne_fichiers']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_interne_fichiers']['multi_type'] = 'ul';
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
    'informations_internes' => 'informations_internes',
  );
  /* Filter criterion: Contenu: Type de donnée (field_interne_type_donnee) */
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['id'] = 'field_interne_type_donnee_tid';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['table'] = 'field_data_field_interne_type_donnee';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['field'] = 'field_interne_type_donnee_tid';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['expose']['operator_id'] = 'field_interne_type_donnee_tid_op';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['expose']['label'] = 'Type d\'information';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['expose']['operator'] = 'field_interne_type_donnee_tid_op';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['expose']['identifier'] = 'field_interne_type_donnee_tid';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    97107646 => 0,
    231346920 => 0,
    193262079 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_interne_type_donnee_tid']['vocabulary'] = 'categorie_intranet';
  /* Filter criterion: Contenu: Commission (field_interne_commission) */
  $handler->display->display_options['filters']['field_interne_commission_tid']['id'] = 'field_interne_commission_tid';
  $handler->display->display_options['filters']['field_interne_commission_tid']['table'] = 'field_data_field_interne_commission';
  $handler->display->display_options['filters']['field_interne_commission_tid']['field'] = 'field_interne_commission_tid';
  $handler->display->display_options['filters']['field_interne_commission_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_interne_commission_tid']['expose']['operator_id'] = 'field_interne_commission_tid_op';
  $handler->display->display_options['filters']['field_interne_commission_tid']['expose']['label'] = 'Thématique';
  $handler->display->display_options['filters']['field_interne_commission_tid']['expose']['operator'] = 'field_interne_commission_tid_op';
  $handler->display->display_options['filters']['field_interne_commission_tid']['expose']['identifier'] = 'field_interne_commission_tid';
  $handler->display->display_options['filters']['field_interne_commission_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    97107646 => 0,
    231346920 => 0,
    193262079 => 0,
    30037204 => 0,
  );
  $handler->display->display_options['filters']['field_interne_commission_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_interne_commission_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_interne_commission_tid']['vocabulary'] = 'commission';

  /* Display: Intranet */
  $handler = $view->new_display('page', 'Intranet', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'intranet';
  $translatables['informations_internes'] = array(
    t('Master'),
    t('Informations internes'),
    t('more'),
    t('Envoyer'),
    t('Réinitialiser'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Résultats par page'),
    t('- All -'),
    t('Offset'),
    t('« premier'),
    t('‹ précédent'),
    t('suivant ›'),
    t('dernier »'),
    t('<h3>Aucun résultat ne correspond à votre requête</h3>
Veuillez la modifier les critères à la gauche de ce message'),
    t('Résumé'),
    t('Fichiers joints'),
    t('Type d\'information'),
    t('Thématique'),
    t('Intranet'),
  );
  $export['informations_internes'] = $view;

  return $export;
}
