<?php
// $Id$

/**
 * @file
 * Admin page callback for the trails module.
 */

/**
 * Builds and returns the trails settings form.
 */
function trails_admin_settings() {
  $form['trails_block_max'] = array(
    '#type' => 'select',
    '#title' => t('Maximum number of items to display'),
    '#options' => drupal_map_assoc(range(1, 200)),
    '#default_value' => variable_get('trails_block_max', ''),
    '#description' => t('This will set the maximum allowable number that can be displayed in a history block'),
    '#required' => TRUE,
  );
  return system_settings_form($form);
}

function trails_wipe_form($form, &$form_submit) {
  $form['confirm'] = array(
    '#title' => t('Confirm wiping'),
    '#type' => 'checkbox',    
    '#description' => t('Are you very very certain you want to wipe all history records ???'),
  );
  
  $form['submit'] = array(
    '#title' => 'Confirmation',
    '#type' => 'fieldset',
    //'#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#states' => array(
      'visible' => array(
        ':input[name="confirm"]' => array('checked' => TRUE),
      ),
    ),
  );
  
  // show form only when checkbox is selected
  $form['submit']['button'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    
  );
  return $form;
}