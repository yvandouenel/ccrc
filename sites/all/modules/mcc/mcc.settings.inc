<?php
/**
 * @file
 * Form and form validation for campaign settings.
 */

/**
 * Define constants for MAilChimp template settings.
 *
 * A basic template ID and the MailChimp default sections.
 */
define('MCC_DEFAULT_TEMPLATE', '1000188');
define('MCC_DEFAULT_TITLE_SECTION', 'header_content');
define('MCC_DEFAULT_BODY_SECTION', 'std_content00');

/**
 * Return a form for general campaign settings.
 */
function mcc_settings_form(&$form, $defaults) {
  $form['mcc']['list_id'] = array(
    '#type' => 'select',
    '#title' => t('MailChimp list'),
    '#default_value' => $defaults ? $defaults['list_id'] : -1,
    '#options' => _mcc_lists_options(),
    '#required' => TRUE,
  );
  $form['mcc']['from_name'] = array(
    '#type' => 'textfield',
    '#title' => t('From name'),
    '#default_value' => $defaults ? $defaults['from_name'] : variable_get('site_name', 'Drupal'),
  );
  $form['mcc']['from_email'] = array(
    '#type' => 'textfield',
    '#title' => t('From email'),
    '#default_value' => $defaults ? $defaults['from_email'] : variable_get('site_mail', FALSE),
  );
  $form['mcc']['template_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Template ID'),
    '#default_value' => $defaults ? $defaults['template_id'] : MCC_DEFAULT_TEMPLATE,
    '#description' => t('MailChimp template for the campaign. Leave blank to reset to defaults.'),
  );
  $form['mcc']['title_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Title section'),
    '#default_value' => $defaults ? $defaults['title_section'] : MCC_DEFAULT_TITLE_SECTION,
    '#description' => t('Title section in the template. Leave blank to reset to defaults.'),
  );
  $form['mcc']['body_section'] = array(
    '#type' => 'textfield',
    '#title' => t('Body section'),
    '#default_value' => $defaults ? $defaults['body_section'] : MCC_DEFAULT_BODY_SECTION,
    '#description' => t('Body section in the template. Leave blank to reset to defaults.'),
  );
}

/**
 * Validate general campaign settings form.
 */
function mcc_settings_form_validate($form, &$form_state) {
  if (isset($form_state['defaults'])) {
    $defaults = $form_state['defaults'];
  }
  else {
    $defaults = FALSE;
  }
  $values = $form_state['values']['mcc'];

  if ($values['from_name'] == '') {
    $form_state['values']['mcc']['from_name'] = $defaults ? $defaults['from_name'] : variable_get('site_name', 'Drupal');
  }

  if ($values['from_email'] == '') {
    $form_state['values']['mcc']['from_email'] = $defaults ? $defaults['from_email'] : variable_get('site_mail', FALSE);
  }
  elseif (!valid_email_address($values['from_email'])) {
    form_set_error('mcc][from_email', t('From email is not valid.'));
  }

  if ($values['template_id'] == '') {
    $form_state['values']['mcc']['template_id'] = $defaults ? $defaults['template_id'] : MCC_DEFAULT_TEMPLATE;
  }
  elseif (!is_numeric($values['template_id'])) {
    form_set_error('mcc][template_id', t('Template ID must be numeric.'));
  }

  if ($values['title_section'] == '') {
    $form_state['values']['mcc']['title_section'] = $defaults ? $defaults['title_section'] : MCC_DEFAULT_TITLE_SECTION;
  }
  elseif (!preg_match('/^[a-zA-Z0-9_]*$/', $values['title_section'])) {
    form_set_error('mcc][title_section', t('Not valid title section.'));
  }

  if ($values['body_section'] == '') {
    $form_state['values']['mcc']['body_section'] = $defaults ? $defaults['body_section'] : MCC_DEFAULT_BODY_SECTION;
  }
  elseif (!preg_match('/^[a-zA-Z0-9_]*$/', $values['body_section'])) {
    form_set_error('mcc][body_section', t('Not valid body section.'));
  }
}
