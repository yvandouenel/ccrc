<?php
/**
 * @file
 * Administration pages for mcc module.
 */

/**
 * Returns sitewide campaign settings form.
 */
function mcc_admin_form($form, &$form_state) {
  module_load_include('inc', 'mcc', 'mcc.settings');
  $defaults = variable_get('mcc', FALSE);
  $form = array();
  $form['mcc'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sitewide default MailChimp campaign settings'),
    '#tree' => TRUE,
    '#description' => t('This setting are the defaults for every node types. Leaving blank this filds will reset the hardcoded MailChimp defaults.'),
  );
  mcc_settings_form($form, $defaults);
  $form['#validate'][] = 'mcc_settings_form_validate';

  return system_settings_form($form);
}
